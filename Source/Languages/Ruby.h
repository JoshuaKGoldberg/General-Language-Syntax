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
        .setClassFunctionsTakeThis(false)
        .setClassMemberVariableDefault(" = nil")
        .setClassPrivacy(false)
        .setClassStartLeft("class ")
        .setClassStartRight("")
        .setClassThis("self")
        .setClassThisAccess(".")
        .setCommentorBlockStart("\"\"\"")
        .setCommentorBlockEnd("\"\"\"")
        .setCommentorInline("#")
        .setConditionStartLeft(" ")
        .setConditionContinueLeft(" ")
        .setConditionEnd("end")
        .setFunctionDefine("def ")
        .setFunctionDefineEnd("end")
        .setMainStartLine("if __name__ == '__main__':")
        .setPrintAsKeyword(true)
        .setPrintFunction("puts")
        .setRangedForLoops(true)
        .setFunctionReturnsExplicit(false)
        .setVariableTypesExplicit(false)
        .setVariableDeclare("")
    );
}

#endif