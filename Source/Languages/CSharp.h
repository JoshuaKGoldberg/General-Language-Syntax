#ifndef _GLSC_SOURCE_LANGUAGES_CSHARP_
#define _GLSC_SOURCE_LANGUAGES_CSHARP_

#include "../GLSC.h"
#include "../Language.h"

using namespace std;

void GLSC::RegisterCSharp() {
    RegisterLanguage(Language()
        .setName("CSharp")
        .setExtension("cs")
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
        .setFileEndLine("}")
        .setFileStartLeft("public class ")
        .setFileStartRight(" {")
        .setFunctionDefineRight(" {")
        .setFunctionDefineEnd("}")
        .setFunctionReturnsExplicit(true)
        .setMainEndLine("}")
        .setMainStartLine("public static void Main() {")
        .setPrintAsKeyword(false)
        .setPrintFunction("System.Console.WriteLine")
        .setRangedForLoops(false)
        .setVariableTypesExplicit(true)
        .setVariableTypesAfterName(false)
        .addTypeAlias("int", "number")
        .addTypeAlias("bool", "boolean")
        );
}

#endif