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
    GLSC_LANG_MEMBER(string, ConditionalStartLeft);
    GLSC_LANG_MEMBER(string, ConditionalStartRight);
    GLSC_LANG_MEMBER(string, ConditionalContinueLeft);
    GLSC_LANG_MEMBER(string, ConditionalContinueRight);
    GLSC_LANG_MEMBER(string, ConditionalEnd);
    GLSC_LANG_MEMBER(string, Elif);
    GLSC_LANG_MEMBER(string, Else);
    GLSC_LANG_MEMBER(string, If);

    // Operators
    GLSC_LANG_MEMBER(string, And);
    GLSC_LANG_MEMBER(string, GreaterThan);
    GLSC_LANG_MEMBER(string, GreaterThanOrEqual);
    GLSC_LANG_MEMBER(string, LessThan);
    GLSC_LANG_MEMBER(string, LessThanOrEqual);
    GLSC_LANG_MEMBER(string, Or);

    // Variables
    GLSC_LANG_MEMBER(string, VariableDeclare);

    // Booleans
    GLSC_LANG_MEMBER(string, BooleanClass);
    GLSC_LANG_MEMBER(string, True);
    GLSC_LANG_MEMBER(string, False);

    // Numbers
    GLSC_LANG_MEMBER(string, NumberClass);

    // Strings
    GLSC_LANG_MEMBER(string, StringClass);
    GLSC_LANG_MEMBER(string, StringLength);

    // Arrays
    GLSC_LANG_MEMBER(string, ArrayClass);
    GLSC_LANG_MEMBER(string, ArrayLength);

    // Functions
    GLSC_LANG_MEMBER(string, FunctionDefine);
    GLSC_LANG_MEMBER(string, FunctionDefineRight);
    GLSC_LANG_MEMBER(string, FucntionDefineEnd);

    // Dictionaries
    GLSC_LANG_MEMBER(string, DictionaryClass);
};

#endif