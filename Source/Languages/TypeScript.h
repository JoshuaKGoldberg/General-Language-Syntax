#ifndef _GLSC_SOURCE_LANGUAGES_TYPESCRIPT_
#define _GLSC_SOURCE_LANGUAGES_TYPESCRIPT_

#include "../GLSC.h"
#include "../Language.h"

using namespace std;

void GLSC::RegisterTypeScript() {
    RegisterLanguage(Language()
        .setName("TypeScript")
        .setExtension("ts")
        .setPrintFunction("console.log")
        .setSemiColon(";")
        .setCommentorBlockStart("/*")
        .setCommentorBlockEnd("*/")
        .setCommentorInline("//")
        .setConditionStartLeft(" (")
        .setConditionStartRight(") {")
        .setConditionContinueLeft("} ")
        .setConditionContinueRight(" {")
        .setConditionEnd("}")
        .setFunctionDefine("function")
        .setFunctionDefineRight(" {")
        .setFunctionDefineEnd("}")
        .setFunctionReturnsExplicit(false)
        .setVariableTypesExplicit(true)
        .setVariableTypesAfterName(true)
        .setVariableTypeMarker(": ")
        .setVariableDeclare("var ")
    );
}

#endif