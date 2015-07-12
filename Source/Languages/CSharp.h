#ifndef _GLSC_SOURCE_LANGUAGES_CSHARP_
#define _GLSC_SOURCE_LANGUAGES_CSHARP_

#include "../GLSC.h"
#include "../Language.h"

using namespace std;

void GLSC::RegisterCSharp() {
    RegisterLanguage(Language()
        .setName("CSharp")
        .setExtension("cs")
        .setPrintFunction("System.Console.WriteLine")
        .setSemiColon(";")
        .setClassConstructorName("") // should default to using class name, then delete here
        .setClassEnd("};")
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
        .setFunctionReturnsExplicit(true)
        .setRangedForLoops(false)
        .setVariableTypesExplicit(true)
        .setVariableTypesAfterName(false)
        .addTypeAlias("int", "number")
        .addTypeAlias("boolean", "bool")
        );
}

#endif