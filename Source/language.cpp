#ifndef _GLSC_SOURCE_LANGUAGE_CPP_
#define _GLSC_SOURCE_LANGUAGE_CPP_

#include <string>
#include <utility>
#include <vector>

#include "language.h"

pair<string, int> Language::PrintCommentBlock(vector<string> &arguments) const {
    return { 
        CommentorInline() + " " + arguments[0], 0
    };
}

#endif