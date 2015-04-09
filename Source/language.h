#ifndef _GLSC_SOURCE_LANGUAGE_H_
#define _GLSC_SOURCE_LANGUAGE_H_

#include <string>
#include <utility>

using namespace std;

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

#define GLSC_LANG_PRINTER(name) \
public: \
    pair<string, int> name(vector<string> &arguments) const;

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

    // Printers
    GLSC_LANG_PRINTER(CommentBlock);
    GLSC_LANG_PRINTER(CommentInline);
    GLSC_LANG_PRINTER(CommentLine);
    GLSC_LANG_PRINTER(FileOpen);
    GLSC_LANG_PRINTER(FileClose);
    GLSC_LANG_PRINTER(FileRead);
    GLSC_LANG_PRINTER(FileReadAmount);
    GLSC_LANG_PRINTER(FileReadCharacter);
    GLSC_LANG_PRINTER(FileReadWord);
    GLSC_LANG_PRINTER(FileReadLine);
    GLSC_LANG_PRINTER(ForEnd);
    GLSC_LANG_PRINTER(ForStart);
    GLSC_LANG_PRINTER(FunctionEnd);
    GLSC_LANG_PRINTER(FunctionStart);
    GLSC_LANG_PRINTER(IfEnd);
    GLSC_LANG_PRINTER(IfStart);
    GLSC_LANG_PRINTER(Import);
    GLSC_LANG_PRINTER(Main);
    GLSC_LANG_PRINTER(VariableDeclare);
    GLSC_LANG_PRINTER(WhileEnd);
    GLSC_LANG_PRINTER(WhileStart);
};

#include "language.cpp"

#endif