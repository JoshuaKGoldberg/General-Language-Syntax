#ifndef _GLSC_SOURCE_LANGUAGES_CPLUSPLUS_
#define _GLSC_SOURCE_LANGUAGES_CPLUSPLUS_

#include "../GLSC.h"
#include "../Language.h"

using namespace std;

void GLSC::RegisterCPlusPlus() {
    RegisterLanguage(Language()
        .setName("C++")
        .setExtension("cpp")
        .setPrintFunction("cout") // should add option for non-Function usage, and << separators
        .setSemiColon(";")
        .setClassConstructorName("") // should default to using class name, then delete here
        .setClassEnd("}")
        .setClassFunctionsTakeThis(false)
        .setClassNew("new ")
        .setClassPrivacy(true)
        .setClassStartLeft("class ")
        .setClassStartRight(" {")
        .setClassThis("this")
        .setClassThisAccess(".")
        .setCommentorBlockStart("/*")
        .setCommentorBlockEnd("*/")
        .setCommentorInline("//")
        .setConditionStartLeft(" (")
        .setConditionStartRight(") {")
        .setConditionContinueLeft("} ")
        .setConditionContinueRight(" {")
        .setConditionEnd("}")
        .setFunctionDefineRight(" {")
        .setFunctionDefineEnd("}")
        .setFunctionReturnsExplicit(false)
        .setRangedForLoops(false)
        .setVariableTypesExplicit(true)
        .setVariableTypesAfterName(false)
        .addTypeAlias("int", "number")
    );
}

#endif