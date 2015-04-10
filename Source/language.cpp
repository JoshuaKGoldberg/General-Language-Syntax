#ifndef _GLSC_SOURCE_LANGUAGE_CPP_
#define _GLSC_SOURCE_LANGUAGE_CPP_

#include <climits>
#include <iterator>
#include <sstream>
#include <string>
#include <utility>
#include <vector>

#include "language.h"


Language::Language() {
    Printers = {
        { "comment block", &Language::CommentBlock },
        { "comment inline", &Language::CommentInline },
        { "comment line", &Language::CommentLine },
        { "if condition start", &Language::IfConditionStart },
        { "if end", &Language::IfEnd },
        { "ifvariable start", &Language::IfVariableStart },
        { "for end", &Language::ForEnd },
        { "for numbers start", &Language::ForNumbersStart },
        { "operation number", &Language::OperationNumber },
        { "operation string", &Language::OperationString },
        { "print line", &Language::PrintLine },
        { "variable declare", &Language::VariableDeclare },
        { "while end", &Language::WhileEnd },
        { "while condition start", &Language::WhileConditionStart }
    };
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

// string i, int start, int end, bool equals = false, int increment = 1
pair<string, int> Language::ForNumbersStart(const vector<string> &arguments, bool isInline = false) const {
    return{ "for start {", 1 };
}

pair<string, int> Language::FunctionEnd(const vector<string> &arguments, bool isInline = false) const {
    return{ "", -1 };
}

pair<string, int> Language::FunctionStart(const vector<string> &arguments, bool isInline = false) const {
    return{ "", 1 };
}

// string left, string operator, string right
pair<string, int> Language::IfConditionStart(const vector<string> &arguments, bool isInline = false) const {
    return{ "if" + ConditionStartLeft() + arguments[0] + " " + arguments[1] + " " + arguments[2] + ConditionStartRight(), 1 };
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

pair<string, int> Language::OperationNumber(const vector<string> &arguments, bool isInline = false) const {
    return{ "", 0 };
}

pair<string, int> Language::OperationString(const vector<string> &arguments, bool isInline = false) const {
    return{ "", 0 };
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
        output += " = " + arguments[2];
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