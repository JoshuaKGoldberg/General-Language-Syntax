#ifndef _GLSC_SOURCE_LANGUAGES_JAVASCRIPT_
#define _GLSC_SOURCE_LANGUAGES_JAVASCRIPT_

#include "../GLSC.h"
#include "../Language.h"

using namespace std;

void GLSC::RegisterJavaScript() {
    RegisterLanguage(Language()
        .setName("JavaScript")
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
        .setVariableTypesExplicit(false)
        .setVariableDeclare("var ")
    );
}

#endif