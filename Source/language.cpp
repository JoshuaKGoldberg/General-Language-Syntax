#ifndef _GLSC_SOURCE_LANGUAGE_CPP_
#define _GLSC_SOURCE_LANGUAGE_CPP_

#include <string>
#include <utility>
#include <vector>

#include "language.h"

pair<string, int> Language::CommentBlock(vector<string> &arguments) const {
    return{ CommentorInline() + " " + arguments[0], 0 };
}

pair<string, int> Language::CommentInline(vector<string> &arguments) const {
    return{ "", 0 };
}

pair<string, int> Language::CommentLine(vector<string> &arguments) const {
    return{ "", 0 };
}

pair<string, int> Language::FileOpen(vector<string> &arguments) const {
    return{ "", 0 };
}

pair<string, int> Language::FileClose(vector<string> &arguments) const {
    return{ "", 0 };
}

pair<string, int> Language::FileRead(vector<string> &arguments) const {
    return{ "", 0 };
}

pair<string, int> Language::FileReadAmount(vector<string> &arguments) const {
    return{ "", 0 };
}

pair<string, int> Language::FileReadCharacter(vector<string> &arguments) const {
    return{ "", 0 };
}

pair<string, int> Language::FileReadWord(vector<string> &arguments) const {
    return{ "", 0 };
}

pair<string, int> Language::FileReadLine(vector<string> &arguments) const {
    return{ "", 0 };
}

pair<string, int> Language::ForEnd(vector<string> &arguments) const {
    return{ "", 0 };
}

pair<string, int> Language::ForStart(vector<string> &arguments) const {
    return{ "", 0 };
}

pair<string, int> Language::FunctionEnd(vector<string> &arguments) const {
    return{ "", 0 };
}

pair<string, int> Language::FunctionStart(vector<string> &arguments) const {
    return{ "", 0 };
}

pair<string, int> Language::IfEnd(vector<string> &arguments) const {
    return{ "", 0 };
}

pair<string, int> Language::IfStart(vector<string> &arguments) const {
    return{ "", 0 };
}

pair<string, int> Language::Import(vector<string> &arguments) const {
    return{ "", 0 };
}

pair<string, int> Language::Main(vector<string> &arguments) const {
    return{ "", 0 };
}

pair<string, int> Language::VariableDeclare(vector<string> &arguments) const {
    return{ "", 0 };
}

pair<string, int> Language::WhileEnd(vector<string> &arguments) const {
    return{ "", 0 };
}

pair<string, int> Language::WhileStart(vector<string> &arguments) const {
    return{ "", 0 };
}

#endif