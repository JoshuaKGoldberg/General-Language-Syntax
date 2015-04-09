#ifndef _GLSC_SOURCE_LANGUAGE_H_
#define _GLSC_SOURCE_LANGUAGE_H_

#include <string>
#include <utility>

using namespace std;

class Language {
public:
    Language() { }
    Language(initializer_list<pair<string, string>> initializers);
    ~Language() { }

    // General information
    string Name;
    string PrintFunction;
    string Semicolon;

    // Comments
    string CommentorBlock;
    string CommentorInline;
    string CommentorLine;

    // Conditionals
    string ConditionalStartLeft;
    string ConditionalStartRight;
    string ConditionalContinueLeft;
    string ConditionalContinueRight;
    string ConditionalEnd;
    string Elif;
    string Else;
    string If;

    // Operators
    string And;
    string GreaterThan;
    string GreaterThanOrEqual;
    string LessThan;
    string LessThanOrEqual;
    string Or;

    // Variables
    string VariableDeclare;

    // Booleans
    string BooleanClass;
    string True;
    string False;

    // Numbers
    string NumberClass;

    // Strings
    string StringClass;
    string StringLength;

    // Arrays
    string ArrayClass;
    string ArrayLength;

    // Functions
    string FunctionDefine;
    string FunctionDefineRight;
    string FucntionDefineEnd;

    // Dictionaries
    string DictionaryClass;
};

#include "language.cpp"

#endif