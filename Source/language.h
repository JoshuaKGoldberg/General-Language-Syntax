#ifndef _GLSC_SOURCE_LANGUAGE_H_
#define _GLSC_SOURCE_LANGUAGE_H_

#include <string>
#include <utility>

using namespace std;

class Language;

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

#define GLSC_LANG_PRINTER_DECLARE(name) \
public: \
    pair<string, int> name(const vector<string> &arguments, bool isInline) const;

typedef pair<string, int>(Language::*PrinterFunction)(const vector<string>&, bool isInline) const;

class Language {
public:
    Language();
    ~Language() { }

    // Aliases
    string TypeAlias(const string& type) const;
    string OperationAlias(const string& type) const;

    Language& addTypeAlias(const string type, const string alias);
    Language& inheritTypeAliases(const Language& language);

    Language& addOperationAlias(const string type, const string alias);
    Language& inheritOperationAliases(const Language& language);

    // Printing
    pair<string, int> Print(const string& function, const vector<string>& arguments, bool isInline) const;

    // General information
    GLSC_LANG_MEMBER(string, Name);
    GLSC_LANG_MEMBER(string, Extension);
    GLSC_LANG_MEMBER(string, PrintFunction);
    GLSC_LANG_MEMBER(string, SemiColon);

    // Comments
    GLSC_LANG_MEMBER(string, CommentorBlockStart);
    GLSC_LANG_MEMBER(string, CommentorBlockEnd);
    GLSC_LANG_MEMBER(string, CommentorInline);

    // Conditionals
    GLSC_LANG_MEMBER(string, ConditionStartLeft);
    GLSC_LANG_MEMBER(string, ConditionStartRight);
    GLSC_LANG_MEMBER(string, ConditionContinueLeft);
    GLSC_LANG_MEMBER(string, ConditionContinueRight);
    GLSC_LANG_MEMBER(string, ConditionEnd);
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
    GLSC_LANG_MEMBER(bool, VariableTypesExplicit);
    GLSC_LANG_MEMBER(bool, VariableTypesAfterName);
    GLSC_LANG_MEMBER(string, VariableTypeMarker);
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

    // Loops
    GLSC_LANG_MEMBER(bool, RangedForLoops)

    // Arrays
    GLSC_LANG_MEMBER(string, ArrayClass);
    GLSC_LANG_MEMBER(string, ArrayLength);

    // Functions
    GLSC_LANG_MEMBER(string, FunctionDefine);
    GLSC_LANG_MEMBER(string, FunctionDefineRight);
    GLSC_LANG_MEMBER(string, FunctionDefineEnd);
    GLSC_LANG_MEMBER(bool, FunctionReturnsExplicit);

    // Dictionaries
    GLSC_LANG_MEMBER(string, DictionaryClass);

    // Classes
    GLSC_LANG_MEMBER(string, ClassConstructorName);
    GLSC_LANG_MEMBER(string, ClassEnd);
    GLSC_LANG_MEMBER(bool, ClassFunctionsTakeThis)
    GLSC_LANG_MEMBER(string, ClassFunctionsThis)
    GLSC_LANG_MEMBER(string, ClassNew)
    GLSC_LANG_MEMBER(string, ClassStartLeft);
    GLSC_LANG_MEMBER(string, ClassStartRight);
    GLSC_LANG_MEMBER(string, ClassThis);
    GLSC_LANG_MEMBER(string, ClassThisAccess);

    // Printers
    GLSC_LANG_PRINTER_DECLARE(ClassConstructorEnd);
    GLSC_LANG_PRINTER_DECLARE(ClassConstructorStart);
    GLSC_LANG_PRINTER_DECLARE(ClassEnd);
    GLSC_LANG_PRINTER_DECLARE(ClassMemberFunctionCall);
    GLSC_LANG_PRINTER_DECLARE(ClassMemberFunctionEnd);
    GLSC_LANG_PRINTER_DECLARE(ClassMemberFunctionStart);
    GLSC_LANG_PRINTER_DECLARE(ClassMemberVariableDeclare);
    GLSC_LANG_PRINTER_DECLARE(ClassMemberVariableGet);
    GLSC_LANG_PRINTER_DECLARE(ClassMemberVariableSet);
    GLSC_LANG_PRINTER_DECLARE(ClassNew);
    GLSC_LANG_PRINTER_DECLARE(ClassStart);
    GLSC_LANG_PRINTER_DECLARE(CommentBlock);
    GLSC_LANG_PRINTER_DECLARE(CommentInline);
    GLSC_LANG_PRINTER_DECLARE(CommentLine);
    GLSC_LANG_PRINTER_DECLARE(Comparison);
    GLSC_LANG_PRINTER_DECLARE(FileOpen);
    GLSC_LANG_PRINTER_DECLARE(FileClose);
    GLSC_LANG_PRINTER_DECLARE(FileRead);
    GLSC_LANG_PRINTER_DECLARE(FileReadAmount);
    GLSC_LANG_PRINTER_DECLARE(FileReadCharacter);
    GLSC_LANG_PRINTER_DECLARE(FileReadWord);
    GLSC_LANG_PRINTER_DECLARE(FileReadLine);
    GLSC_LANG_PRINTER_DECLARE(ForEnd);
    GLSC_LANG_PRINTER_DECLARE(ForNumbersStart);
    GLSC_LANG_PRINTER_DECLARE(FunctionCall);
    GLSC_LANG_PRINTER_DECLARE(FunctionEnd);
    GLSC_LANG_PRINTER_DECLARE(FunctionStart);
    GLSC_LANG_PRINTER_DECLARE(FunctionReturn);
    GLSC_LANG_PRINTER_DECLARE(IfEnd);
    GLSC_LANG_PRINTER_DECLARE(IfConditionStart);
    GLSC_LANG_PRINTER_DECLARE(IfVariableStart);
    GLSC_LANG_PRINTER_DECLARE(Import);
    GLSC_LANG_PRINTER_DECLARE(Main);
    GLSC_LANG_PRINTER_DECLARE(Operation);
    GLSC_LANG_PRINTER_DECLARE(PrintLine)
    GLSC_LANG_PRINTER_DECLARE(VariableDeclare);
    GLSC_LANG_PRINTER_DECLARE(VariableDeclarePartial);
    GLSC_LANG_PRINTER_DECLARE(WhileConditionStart);
    GLSC_LANG_PRINTER_DECLARE(WhileEnd);
    GLSC_LANG_PRINTER_DECLARE(WhileVariableStart);

private:
    unordered_map<string, PrinterFunction> Printers;
    unordered_map<string, string> TypeAliases;
    unordered_map<string, string> OperationAliases;
};

#include "language.cpp"

#endif