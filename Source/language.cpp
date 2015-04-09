#ifndef _GLSC_SOURCE_LANGUAGE_CPP_
#define _GLSC_SOURCE_LANGUAGE_CPP_

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
        { "print line", &Language::PrintLine },
        { "variable declare", &Language::VariableDeclare }
    };
}

pair<string, int> Language::Print(const string& function, const vector<string>& arguments, bool isInline = false) const {
    return (this->*(Printers.find(function)->second))(arguments, isInline);
}

pair<string, int> Language::CommentBlock(const vector<string> &arguments, bool isInline = false) const {
    return{ CommentorInline() + " " + arguments[0], 0 };
}

pair<string, int> Language::CommentInline(const vector<string> &arguments, bool isInline = false) const {
    return{ "", 0 };
}

pair<string, int> Language::CommentLine(const vector<string> &arguments, bool isInline = false) const {
    return{ "", 0 };
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
    return{ "", 0 };
}

pair<string, int> Language::ForStart(const vector<string> &arguments, bool isInline = false) const {
    return{ "", 0 };
}

pair<string, int> Language::FunctionEnd(const vector<string> &arguments, bool isInline = false) const {
    return{ "", 0 };
}

pair<string, int> Language::FunctionStart(const vector<string> &arguments, bool isInline = false) const {
    return{ "", 0 };
}

pair<string, int> Language::IfEnd(const vector<string> &arguments, bool isInline = false) const {
    return{ "", 0 };
}

pair<string, int> Language::IfStart(const vector<string> &arguments, bool isInline = false) const {
    return{ "", 0 };
}

pair<string, int> Language::Import(const vector<string> &arguments, bool isInline = false) const {
    return{ "", 0 };
}

pair<string, int> Language::Main(const vector<string> &arguments, bool isInline = false) const {
    return{ "", 0 };
}

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

// string name, string type, string value = (nothing)
pair<string, int> Language::WhileEnd(const vector<string> &arguments, bool isInline = false) const {
    return{ "", 0 };
}

pair<string, int> Language::WhileStart(const vector<string> &arguments, bool isInline = false) const {
    return{ "", 0 };
}

#endif