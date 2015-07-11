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
        { "class end", &Language::ClassEnd },
        { "class member variable", &Language::ClassMemberVariable },
        { "class member function ", &Language::ClassMemberFunction },
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
        { "while condition start", &Language::WhileConditionStart },
        { "while end", &Language::WhileEnd },
        { "while variable start", &Language::WhileVariableStart }
    };

    TypeAliases = {
        {}
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
}

string Language::TypeAlias(const string& type) const {
    return TypeAliases.find(type) == TypeAliases.end()
        ? type : TypeAliases.find(type)->second;
}

string Language::OperationAlias(const string& operation) const {
    return OperationAliases.find(operation) == OperationAliases.end()
        ? operation : OperationAliases.find(operation)->second;
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


pair<string, int> Language::Print(const string& function, const vector<string>& arguments, bool isInline = false) const {
    unordered_map<string, PrinterFunction>::const_iterator itr = Printers.find(function);
    if (itr == Printers.end()) {
        throw string("Function not found: " + function);
    }

    return (this->*(itr->second))(arguments, isInline);
}

GLSC_LANG_PRINTER_DEFINE(ClassEnd) {
    return{ ConditionEnd() + SemiColon(), -1 };
}

// string name
GLSC_LANG_PRINTER_DEFINE(ClassMemberVariable) {
    return{ "class start", 1 };
}

// string privacy, { function }
GLSC_LANG_PRINTER_DEFINE(ClassMemberFunction) {
    vector<string> functionArguments = arguments;

    return{ "class member function", 1 };
}

GLSC_LANG_PRINTER_DEFINE(ClassStart) {
    GLSC_LANG_ARGUMENTS_MIN("ClasStart", 1);
    return{ "class " + arguments[0] + ConditionStartRight(), 1 };
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
// i int 0 lessthan 7 increase 1
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

    vector<string> variableArgs = { i, type, initial };
    output += VariableDeclare(variableArgs, false).first;

    vector<string> comparisonArgs = { i, comparison, boundary };
    output += " " + Comparison(comparisonArgs, false).first + SemiColon();

    vector<string> operationArgs = { i, direction, change };
    output += " " + Operation(operationArgs, false).first;

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
    size_t i;

    if (FunctionReturnsExplicit()) {
        output += arguments[1] + " ";
    }

    output += FunctionDefine() + " " + arguments[0] + "(";

    if (arguments.size() > 2) {
        for (i = 2; i < arguments.size() - 2; i += 2) {
            if (VariableTypesExplicit()) {
                if (VariableTypesAfterName()) {
                    output += arguments[i] + VariableTypeMarker() + TypeAlias(arguments[i + 1]) + ", ";
                }
                else {
                    output += TypeAlias(arguments[i + 1]) + arguments[i] + ", ";
                }
            }
            else {
                output += arguments[i] + ", ";
            }
        }

        if (VariableTypesExplicit()) {
            if (VariableTypesAfterName()) {
                output += arguments[i] + VariableTypeMarker() + TypeAlias(arguments[i + 1]);
            }
            else {
                output += TypeAlias(arguments[i + 1]) + arguments[i];
            }
        }
        else {
            output += arguments[i];
        }
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
    return{ arguments[0] + " " + OperationAlias(arguments[1]) + " " + arguments[2], 0 };
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
    string output = VariableDeclare();

    if (VariableTypesExplicit())
    {
        if (VariableTypesAfterName()) {
            output += arguments[0] + VariableTypeMarker() + TypeAlias(arguments[1]);
        }
        else {
            output += TypeAlias(arguments[1]) + arguments[0];
        }
    }
    else {
        output += arguments[0];
    }

    if (arguments.size() >= 3) {
        output += " = " + arguments[2];
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