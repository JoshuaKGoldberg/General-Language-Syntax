#ifndef _GLSC_SOURCE_LANGUAGE_H_
#define _GLSC_SOURCE_LANGUAGE_H_

#include <string>
#include <utility>

#define GLSC_LANG_MEMBER(type, name) \
private: \
    type _##name; \
    \
public: \
    type name() const { \
        return _##name; \
    } \
    \
    Language& set##name(const type input_##name) { \
        _##name = input_##name; \
        return *this; \
    } 

using namespace std;

class Language {
public:
    Language() { }
    ~Language() { }

    // General information
    GLSC_LANG_MEMBER(string, Name);
    GLSC_LANG_MEMBER(string, PrintFunction);
    GLSC_LANG_MEMBER(string, SemiColon);

    // Comments
    GLSC_LANG_MEMBER(string, CommentorBlockStart);
    GLSC_LANG_MEMBER(string, CommentorBlockEnd);
    GLSC_LANG_MEMBER(string, CommentorInline);

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

#endif