#ifndef _GLSC_SOURCE_LANGUAGE_CPP_
#define _GLSC_SOURCE_LANGUAGE_CPP_

#include <climits>
#include <cstdlib>
#include <iterator>
#include <sstream>
#include <string>
#include <utility>
#include <unordered_map>
#include <vector>

#include "language.h"

#define STRINGIFY(a) #a

#define GLSC_LANG_PRINTER_DEFINE(name) \
    pair<string, int> Language::name(const vector<string> &arguments, bool isInline = false) const \

#define GLSC_LANG_ARGUMENTS_MIN(name, minimumArguments) \
    if (arguments.size() < minimumArguments) { \
        throw string("Not enough arguments given to " name "."); \
                }

Language::Language() {
    Printers = {
        { "class constructor end", &Language::ClassConstructorEnd },
        { "class constructor start", &Language::ClassConstructorStart },
        { "class end", &Language::ClassEnd },
        { "class member function call", &Language::ClassMemberFunctionCall },
        { "class member function end", &Language::ClassMemberFunctionEnd },
        { "class member function start", &Language::ClassMemberFunctionStart },
        { "class member variable declare", &Language::ClassMemberVariableDeclare },
        { "class member variable get", &Language::ClassMemberVariableGet },
        { "class member variable set", &Language::ClassMemberVariableSet },
        { "class new", &Language::ClassNew },
        { "class start", &Language::ClassStart },
        { "comment block", &Language::CommentBlock },
        { "comment inline", &Language::CommentInline },
        { "comment line", &Language::CommentLine },
        { "comparison", &Language::Comparison },
        { "for end", &Language::ForEnd },
        { "for numbers start", &Language::ForNumbersStart },
        { "function call", &Language::FunctionCall },
        { "function end", &Language::FunctionEnd },
        { "function start", &Language::FunctionStart },
        { "function return", &Language::FunctionReturn },
        { "if condition start", &Language::IfConditionStart },
        { "if end", &Language::IfEnd },
        { "if variable start", &Language::IfVariableStart },
        { "operation", &Language::Operation },
        { "print line", &Language::PrintLine },
        { "variable declare", &Language::VariableDeclare },
        { "variable declare partial", &Language::VariableDeclarePartial },
        { "while condition start", &Language::WhileConditionStart },
        { "while end", &Language::WhileEnd },
        { "while variable start", &Language::WhileVariableStart }
    };

    OperationAliases = {
        { "equals", "=" },
        { "plus", "+" },
        { "minus", "-" },
        { "times", "*" },
        { "divided", "/" },
        { "increaseby", "+=" },
        { "decreaseby", "-=" },
        { "multiplyby", "*=" },
        { "divideby", "/=" },
        { "lessthan", "<" },
        { "greaterthan", ">" },
        { "lessthanequal", "<=" },
        { "greaterthanequal", ">=" },
    };

    TypeAliases = {};

    ValueAliases = {};
}

string Language::TypeAlias(const string& type) const {
    return TypeAliases.find(type) == TypeAliases.end()
        ? type : TypeAliases.find(type)->second;
}

string Language::OperationAlias(const string& operation) const {
    return OperationAliases.find(operation) == OperationAliases.end()
        ? operation : OperationAliases.find(operation)->second;
}

string Language::ValueAlias(const string& operation) const {
    return ValueAliases.find(operation) == ValueAliases.end()
        ? operation : ValueAliases.find(operation)->second;
}

Language& Language::addTypeAlias(const string type, const string alias) {
    TypeAliases[alias] = type;
    return *this;
}

Language& Language::inheritTypeAliases(const Language& language) {
    for (const auto& pair : language.TypeAliases) {
        addTypeAlias(pair.second, pair.first);
    }

    return *this;
}

Language& Language::addOperationAlias(const string type, const string alias) {
    OperationAliases[alias] = type;
    return *this;
}

Language& Language::inheritOperationAliases(const Language& language) {
    for (const auto& pair : language.OperationAliases) {
        addOperationAlias(pair.second, pair.first);
    }

    return *this;
}

Language& Language::addValueAlias(const string value, const string alias) {
    ValueAliases[alias] = value;
    return *this;
}

Language& Language::inheritValueAliases(const Language& language) {
    for (const auto& pair : language.ValueAliases) {
        addValueAlias(pair.second, pair.first);
    }

    return *this;
}


pair<string, int> Language::Print(const string& function, const vector<string>& arguments, bool isInline = false) const {
    unordered_map<string, PrinterFunction>::const_iterator itr = Printers.find(function);

    if (itr == Printers.end()) {
        return{ "Function not found: " + function, 0 };
    }

    return (this->*(itr->second))(arguments, isInline);
}

GLSC_LANG_PRINTER_DEFINE(ClassConstructorEnd) {
    return{ FunctionDefineEnd(), -1 };
}

// string name[, string argumentName, string argumentType, ...]
GLSC_LANG_PRINTER_DEFINE(ClassConstructorStart) {
    string output = ClassConstructorName();
    vector<string> variableDeclarationArguments(2, "");
    size_t i;

    if (output.size() == 0) {
        output = arguments[0];
    }

    output += "(";

    if (ClassFunctionsTakeThis()) {
        variableDeclarationArguments[0] = ClassFunctionsThis();
        variableDeclarationArguments[1] = arguments[0];

        output += VariableDeclarePartial(variableDeclarationArguments, true).first;
    }

    // All arguments are added using VariableDeclarePartial
    if (arguments.size() > 1) {
        if (ClassFunctionsTakeThis()) {
            output += ", ";
        }

        for (i = 1; i < arguments.size(); i += 2) {
            variableDeclarationArguments[0] = arguments[i];
            variableDeclarationArguments[1] = arguments[i + 1];

            output += VariableDeclarePartial(variableDeclarationArguments, true).first + ", ";
        }

        // The last argument does not have the last ", " at the end
        output.erase(output.size() - 2);
    }

    output += ")" + FunctionDefineRight();
    return{ output, 1 };
}

GLSC_LANG_PRINTER_DEFINE(ClassEnd) {
    return{ ClassEnd(), -1 };
}

// string variable, string function, [, string argumentName, string argumentType, ...]
GLSC_LANG_PRINTER_DEFINE(ClassMemberFunctionCall) {
    string output = arguments[0] + "." + arguments[1] + "(";
    size_t i;

    if (arguments.size() > 2) {
        for (i = 2; i < arguments.size() - 1; i += 1) {
            output += arguments[i] + ", ";
        }
        output += arguments[i];
    }

    output += ")";
    return{ output, 0 };
}

GLSC_LANG_PRINTER_DEFINE(ClassMemberFunctionEnd) {
    return{ FunctionDefineEnd(), -1 };
}

// string class, string visibility, string name, string return, [, string argumentName, string argumentType...]
GLSC_LANG_PRINTER_DEFINE(ClassMemberFunctionStart) {
    string output = ClassFunctionsStart();
    vector<string> variableDeclarationArguments(2, "");
    size_t i;

    if (FunctionReturnsExplicit()) {
        output = arguments[3] + " ";
    }

    if (ClassPrivacy()) {
        output = arguments[1] + " " + output;
    }

    output += arguments[2] + "(";

    if (ClassFunctionsTakeThis()) {
        variableDeclarationArguments[0] = ClassFunctionsThis();
        variableDeclarationArguments[1] = arguments[0];

        output += VariableDeclarePartial(variableDeclarationArguments, true).first;
    }

    // All arguments are added using VariableDeclarePartial
    if (arguments.size() > 4) {
        if (ClassFunctionsTakeThis()) {
            output += ", ";
        }

        for (i = 4; i < arguments.size(); i += 2) {
            variableDeclarationArguments[0] = arguments[i];
            variableDeclarationArguments[1] = arguments[i + 1];

            output += VariableDeclarePartial(variableDeclarationArguments, true).first + ", ";
        }

        // The last argument does not have the last ", " at the end
        output.erase(output.size() - 2);
    }

    output += ")" + FunctionDefineRight();
    return{ output, 1 };
}

// string name, string visibility, string type
GLSC_LANG_PRINTER_DEFINE(ClassMemberVariableDeclare) {
    vector<string> declarationArguments = { arguments[0], arguments[2] };
    pair<string, int> output = VariableDeclarePartial(declarationArguments, true);

    if (ClassPrivacy()) {
        output.first = arguments[1] + " " + output.first;
    }

    output.first = output.first + ClassMemberVariableDefault() + SemiColon();

    return output;
}

// string name
GLSC_LANG_PRINTER_DEFINE(ClassMemberVariableGet) {
    return{ ClassThis() + ClassThisAccess() + arguments[0], 0 };
}

// string name, string value
GLSC_LANG_PRINTER_DEFINE(ClassMemberVariableSet) {
    string output = ClassThis() + ClassThisAccess();
    output += arguments[0] + " " + OperationAlias("equals") + " " + arguments[1];
    output += SemiColon();
    return{ output, 0 };
}

// string name
GLSC_LANG_PRINTER_DEFINE(ClassStart) {
    return{ ClassStartLeft() + arguments[0] + ClassStartRight(), 1 };
}

// string name[, string argumentName, string argumentType, ...]
GLSC_LANG_PRINTER_DEFINE(ClassNew) {
    string output = ClassNew() + arguments[0] + "(";
    size_t i;

    if (arguments.size() > 1) {
        for (i = 1; i < arguments.size(); i += 1) {
            output += arguments[i] + ", ";
        }

        // The last argument does not have the last ", " at the end
        output.erase(output.size() - 2);
    }

    output += ")";
    return{ output, 0 };
}

// string message, ...
GLSC_LANG_PRINTER_DEFINE(CommentBlock) {
    string output = CommentorBlockStart() + "\n";

    for (size_t i = 0; i < arguments.size(); i += 1) {
        output += arguments[i] + "\n";
    }

    output += CommentorBlockEnd();

    return{ output, 0 };
}

// string message, ...
GLSC_LANG_PRINTER_DEFINE(CommentInline) {
    pair<string, int> output = CommentLine(arguments, isInline);
    output.second = INT_MIN;
    return output;
}

// string message, ...
GLSC_LANG_PRINTER_DEFINE(CommentLine) {
    string output = CommentorInline() + " ";
    size_t i;

    for (i = 0; i < arguments.size() - 1; i += 1) {
        output += arguments[i] + " ";
    }

    output += arguments[i];

    return{ output, 0 };
}

// string left, string comparison, string right
GLSC_LANG_PRINTER_DEFINE(Comparison) {
    GLSC_LANG_ARGUMENTS_MIN("Comparison", 3);
    return{ arguments[0] + " " + OperationAlias(arguments[1]) + " " + arguments[2], 0 };
}

GLSC_LANG_PRINTER_DEFINE(FileOpen) {
    return{ "", 0 };
}

GLSC_LANG_PRINTER_DEFINE(FileClose) {
    return{ "", 0 };
}

GLSC_LANG_PRINTER_DEFINE(FileRead) {
    return{ "", 0 };
}

GLSC_LANG_PRINTER_DEFINE(FileReadAmount) {
    return{ "", 0 };
}

GLSC_LANG_PRINTER_DEFINE(FileReadCharacter) {
    return{ "", 0 };
}

GLSC_LANG_PRINTER_DEFINE(FileReadWord) {
    return{ "", 0 };
}

GLSC_LANG_PRINTER_DEFINE(FileReadLine) {
    return{ "", 0 };
}

GLSC_LANG_PRINTER_DEFINE(ForEnd) {
    return{ ConditionEnd(), -1 };
}

// string i, string type, string initial, string comparison, string boundary, string direction, string change
// e.x. i int 0 lessthan 7 increaseby 1
GLSC_LANG_PRINTER_DEFINE(ForNumbersStart) {
    GLSC_LANG_ARGUMENTS_MIN("ForNumbersStart", 7);
    string output = "for" + ConditionStartLeft();

    const string& i = arguments[0];
    const string& type = TypeAlias(arguments[1]);
    const string& initial = arguments[2];
    const string& comparison = arguments[3];
    const string& boundary = arguments[4];
    const string& direction = arguments[5];
    const string& change = arguments[6];

    if (RangedForLoops()) {
        vector<string> variableArgs = { i, type };
        output += VariableDeclare(variableArgs, false).first;

        output += " in range(";
        output += initial + ", " + boundary;

        if (direction == "increaseby") {
            if (change != "1") {
                output += ", " + change;
            }
        }
        else if (direction == "decreaseby") {
            output += ", -" + change;
        }

        output += ")";
    }
    else {
        vector<string> variableArgs = { i, type, initial };
        output += VariableDeclare(variableArgs, false).first;

        vector<string> comparisonArgs = { i, comparison, boundary };
        output += " " + Comparison(comparisonArgs, false).first + SemiColon();

        vector<string> operationArgs = { i, direction, change };
        output += " " + Operation(operationArgs, false).first;
    }

    output += ConditionStartRight();

    return{ output, 1 };
}

GLSC_LANG_PRINTER_DEFINE(FunctionCall) {
    GLSC_LANG_ARGUMENTS_MIN("FunctionCall", 1);

    string output = arguments[0] + "(";
    size_t i;

    if (arguments.size() > 1) {
        for (i = 1; i < arguments.size() - 1; i += 1) {
            output += arguments[i] + ", ";
        }
        output += arguments[i];
    }

    output += ")";

    if (!isInline) {
        output += SemiColon();
    }

    return{ output, 0 };
}

GLSC_LANG_PRINTER_DEFINE(FunctionEnd) {
    return{ FunctionDefineEnd(), -1 };
}

// string name, string return[, string argumentName, string argumentType, ...]
GLSC_LANG_PRINTER_DEFINE(FunctionStart) {
    string output = "";
    vector<string> variableDeclarationArguments(2, "");
    size_t i;

    if (FunctionReturnsExplicit() && arguments[1] != "") {
        output += arguments[1] + " ";
    }

    output += FunctionDefine() + arguments[0] + "(";

    // All arguments are added using VariableDeclarePartial
    if (arguments.size() > 2) {
        for (i = 2; i < arguments.size(); i += 2) {
            variableDeclarationArguments[0] = arguments[i];
            variableDeclarationArguments[1] = arguments[i + 1];

            output += VariableDeclarePartial(variableDeclarationArguments, true).first + ", ";
        }

        // The last argument does not have the last ", " at the end
        output.erase(output.size() - 2);
    }

    output += ")" + FunctionDefineRight();
    return{ output, 1 };
}

// string value
GLSC_LANG_PRINTER_DEFINE(FunctionReturn) {
    return{ "return " + arguments[0] + SemiColon(), 0 };
}

// string left, string operator, string right
GLSC_LANG_PRINTER_DEFINE(IfConditionStart) {
    return{ "if" + ConditionStartLeft() + arguments[0] + " " + OperationAlias(arguments[1]) + " " + arguments[2] + ConditionStartRight(), 1 };
}

GLSC_LANG_PRINTER_DEFINE(IfEnd) {
    return{ ConditionEnd(), -1 };
}

// string variable
GLSC_LANG_PRINTER_DEFINE(IfVariableStart) {
    return{ "if" + ConditionStartLeft() + arguments[0] + ConditionStartRight(), 1 };
}

GLSC_LANG_PRINTER_DEFINE(Import) {
    return{ "", 0 };
}

GLSC_LANG_PRINTER_DEFINE(Main) {
    return{ "", 0 };
}

// string i, string direction, string differece
GLSC_LANG_PRINTER_DEFINE(Operation) {
    return{ arguments[0] + " " + OperationAlias(arguments[1]) + " " + ValueAlias(arguments[2]), 0 };
}

// string message, ...
GLSC_LANG_PRINTER_DEFINE(PrintLine) {
    string output = PrintFunction() + "(";
    size_t i;

    for (i = 0; i < arguments.size() - 1; i += 1) {
        output += arguments[i] + ", ";
    }

    output += arguments[i];
    output += ")";

    if (!isInline) {
        output += SemiColon();
    }

    return{ output, 0 };
}

// string name, string type[, string value]
GLSC_LANG_PRINTER_DEFINE(VariableDeclare) {
    pair<string, int> test = VariableDeclarePartial(arguments, isInline);

    test.first = VariableDeclare() + test.first;

    return test;
}

// string name, string type[, string value]
GLSC_LANG_PRINTER_DEFINE(VariableDeclarePartial) {
    string output;

    if (VariableTypesExplicit())
    {
        if (VariableTypesAfterName()) {
            output += arguments[0] + VariableTypeMarker() + TypeAlias(arguments[1]);
        }
        else {
            output += TypeAlias(arguments[1]) + " " + arguments[0];
        }
    }
    else {
        output += arguments[0];
    }

    if (arguments.size() >= 3) {
        output += " = " + ValueAlias(arguments[2]);
    }

    if (!isInline) {
        output += SemiColon();
    }

    return{ output, 0 };
}

// string left, string operator, string right
GLSC_LANG_PRINTER_DEFINE(WhileConditionStart) {
    return{ "while" + ConditionStartLeft() + arguments[0] + " " + OperationAlias(arguments[1]) + " " + arguments[2] + ConditionStartRight(), 1 };
}

GLSC_LANG_PRINTER_DEFINE(WhileEnd) {
    return{ ConditionEnd(), -1 };
}

// string variable
GLSC_LANG_PRINTER_DEFINE(WhileVariableStart) {
    return{ "while" + ConditionStartLeft() + OperationAlias(arguments[0]) + ConditionStartRight(), 1 };
}

#endif