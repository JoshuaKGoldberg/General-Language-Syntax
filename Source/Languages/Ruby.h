#ifndef _GLSC_SOURCE_LANGUAGES_RUBY_
#define _GLSC_SOURCE_LANGUAGES_RUBY_

#include "../GLSC.h"
#include "../Language.h"

using namespace std;

void GLSC::RegisterRuby() {
    RegisterLanguage(Language()
        .setName("Ruby")
        .setExtension("rb")
        .setSemiColon("")
        .setClassConstructorName("def __init__")
        .setClassFunctionsStart("def ")
        .setClassFunctionsTakeThis(true)
        .setClassFunctionsThis("self")
        .setClassMemberVariableDefault(" = None")
        .setClassPrivacy(false)
        .setClassStartLeft("class ")
        .setClassStartRight(":")
        .setClassThis("self")
        .setClassThisAccess(".")
        .setCommentorBlockStart("\"\"\"")
        .setCommentorBlockEnd("\"\"\"")
        .setCommentorInline("#")
        .setConditionStartLeft(" ")
        .setConditionStartRight(":")
        .setConditionContinueLeft(" ")
        .setConditionContinueRight(":")
        .setConditionEnd("")
        .setFunctionDefine("def ")
        .setFunctionDefineRight(":")
        .setFunctionDefineEnd("")
        .setMainStartLine("if __name__ == '__main__':")
        .setPrintFunction("puts")
        .setPrintAsKeyword(true)
        .setRangedForLoops(true)
        .setFunctionReturnsExplicit(false)
        .setVariableTypesExplicit(false)
        .setVariableDeclare("")
        .addValueAlias("False", "false")
        .addValueAlias("True", "true")
    );
}

#endif