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

Language::Language() {
    Printers = {
        { "comment block", &Language::CommentBlock },
        { "comment inline", &Language::CommentInline },
        { "comment line", &Language::CommentLine },
        { "comparison", &Language::Comparison },
        { "for end", &Language::ForEnd },
        { "for numbers start", &Language::ForNumbersStart },
        { "function call", &Language::FunctionCall },
        { "function define end", &Language::FunctionDefineEnd },
        { "function define start", &Language::FunctionDefineStart },
        { "function return", &Language::FunctionReturn },
        { "if condition start", &Language::IfConditionStart },
        { "if end", &Language::IfEnd },
        { "if variable start", &Language::IfVariableStart },
        { "operation", &Language::Operation },
        { "print line", &Language::PrintLine },
        { "variable declare", &Language::VariableDeclare },
        { "while end", &Language::WhileEnd },
        { "while condition start", &Language::WhileConditionStart }
    };

    TypeAliases = {
        {}
    };

    OperationAliases= {
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
        ? type : TypeAliases.find(type)->first;
}

string Language::OperationAlias(const string& operation) const {
    return OperationAliases.find(operation) == OperationAliases.end()
        ? operation : OperationAliases.find(operation)->second;
}

pair<string, int> Language::Print(const string& function, const vector<string>& arguments, bool isInline = false) const {
    unordered_map<string, PrinterFunction>::const_iterator itr = Printers.find(function);

    if (itr == Printers.end()) {
        throw "Function not found: " + function;
    }

    return (this->*(itr->second))(arguments, isInline);
}

// string message, ...
pair<string, int> Language::CommentBlock(const vector<string> &arguments, bool isInline = false) const {
    string output = CommentorBlockStart() + "\n";

    for (size_t i = 0; i < arguments.size(); i += 1) {
        output += arguments[i] + "\n";
    }

    output += CommentorBlockEnd();

    return{ output, 0 };
}

// string message, ...
pair<string, int> Language::CommentInline(const vector<string> &arguments, bool isInline = false) const {
    pair<string, int> output = CommentLine(arguments, isInline);
    output.second = INT_MIN;
    return output;
}

// string message, ...
pair<string, int> Language::CommentLine(const vector<string> &arguments, bool isInline = false) const {
    string output = CommentorInline() + " ";
    size_t i;

    for (i = 0; i < arguments.size() - 1; i += 1) {
        output += arguments[i] + " ";
    }

    output += arguments[i];

    return{ output, 0 };
}

// string left, string comparison, string right
pair<string, int> Language::Comparison(const vector<string> &arguments, bool isInline = false) const {
    return{ arguments[0] + " " + OperationAlias(arguments[1]) + " " + arguments[2], 0 };
}

pair<string, int> Language::FileOpen(const vector<string> &arguments, bool isInline = false) const {
    return{ "", 0 };
}

pair<string, int> Language::FileClose(const vector<string> &arguments, bool isInline = false) const {
    return{ "", 0 };
}

pair<string, int> Language::FileRead(const vector<string> &arguments, bool isInline = false) const {
    return{ "", 0 };
}

pair<string, int> Language::FileReadAmount(const vector<string> &arguments, bool isInline = false) const {
    return{ "", 0 };
}

pair<string, int> Language::FileReadCharacter(const vector<string> &arguments, bool isInline = false) const {
    return{ "", 0 };
}

pair<string, int> Language::FileReadWord(const vector<string> &arguments, bool isInline = false) const {
    return{ "", 0 };
}

pair<string, int> Language::FileReadLine(const vector<string> &arguments, bool isInline = false) const {
    return{ "", 0 };
}

pair<string, int> Language::ForEnd(const vector<string> &arguments, bool isInline = false) const {
    return{ ConditionEnd(), -1 };
}

// string i, string type, string initial, string comparison, string boundary, string direction, string change
// i int 0 lessthan 7 increase 1
pair<string, int> Language::ForNumbersStart(const vector<string> &arguments, bool isInline = false) const {
    string output = "for" + ConditionStartLeft();

    const string& i = arguments[0];
    const string& type = arguments[1];
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

pair<string, int> Language::FunctionCall(const vector<string> &arguments, bool isInline = false) const {
    return{ "", 1 };
}

// string name, string return[, string argumentName, string argumentType, ...]
pair<string, int> Language::FunctionDefineEnd(const vector<string> &arguments, bool isInline = false) const {
    return{ FunctionDefineEnd(), -1 };
}

pair<string, int> Language::FunctionDefineStart(const vector<string> &arguments, bool isInline = false) const {
    string output = "";
    size_t i;

    if (FunctionReturnsExplicit()) {
        output += arguments[1] + " ";
    }


    output += FunctionDefine() + " " + arguments[0] + "(";

    for (i = 2; i < arguments.size() - 2; i += 2) {
        if (VariableTypesExplicit()) {
            output += TypeAlias(arguments[i + 1]) + " ";
        }

        output += arguments[i] + ", ";
    }

    if (VariableTypesExplicit()) {
        output += TypeAlias(arguments[i + 1]) + " ";
    }
    output += arguments[i];

    output += ")" + FunctionDefineRight();

    return{ output, 1 };
}

// string value
pair<string, int> Language::FunctionReturn(const vector<string> &arguments, bool isInline = false) const {
    return{ "return " + arguments[0] + SemiColon(), 0 };
}

// string left, string operator, string right
pair<string, int> Language::IfConditionStart(const vector<string> &arguments, bool isInline = false) const {
    return{ "if" + ConditionStartLeft() + arguments[0] + " " + OperationAlias(arguments[1]) + " " + arguments[2] + ConditionStartRight(), 1 };
}

pair<string, int> Language::IfEnd(const vector<string> &arguments, bool isInline = false) const {
    return{ ConditionEnd(), -1 };
}

// string variable
pair<string, int> Language::IfVariableStart(const vector<string> &arguments, bool isInline = false) const {
    return{ "if" + ConditionStartLeft() + arguments[0] + ConditionStartRight(), 0 };
}

pair<string, int> Language::Import(const vector<string> &arguments, bool isInline = false) const {
    return{ "", 0 };
}

pair<string, int> Language::Main(const vector<string> &arguments, bool isInline = false) const {
    return{ "", 0 };
}

// string i, string direction, string differece
pair<string, int> Language::Operation(const vector<string> &arguments, bool isInline = false) const {
    return{ arguments[0] + " " + OperationAlias(arguments[1]) + " " + arguments[2], 0 };
}

// string message, ...
pair<string, int> Language::PrintLine(const vector<string> &arguments, bool isInline = false) const {
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
pair<string, int> Language::VariableDeclare(const vector<string> &arguments, bool isInline = false) const {
    string output = VariableDeclare();

    if (VariableTypesExplicit()) {
        output += arguments[1] + " ";
    }

    output += arguments[0];

    if (arguments.size() >= 3) {
        output += " = " + TypeAlias(arguments[2]);
    }

    if (!isInline) {
        output += SemiColon();
    }

    return{ output, 0 };
}

// string left, string operator, string right
pair<string, int> Language::WhileConditionStart(const vector<string> &arguments, bool isInline = false) const {
    return{ "if" + ConditionStartLeft() + arguments[0] + " " + arguments[1] + " " + arguments[2] + ConditionStartRight(), 1 };
}

pair<string, int> Language::WhileEnd(const vector<string> &arguments, bool isInline = false) const {
    return{ ConditionEnd(), -1 };
}

// string value
pair<string, int> Language::WhileVariableStart(const vector<string> &arguments, bool isInline = false) const {
    return{ "if" + ConditionStartLeft() + arguments[0] + ConditionStartRight(), 1 };
}

#endif