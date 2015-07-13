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
        .setMainEndLines(vector<string> { "}", "}" })
        .setMainIndents(1)
        .setMainStartLines(vector<string> { "public class Main {", "public static void Main() {" })
        .setMainUsed(true)
        .setRangedForLoops(false)
        .setVariableTypesExplicit(true)
        .setVariableTypesAfterName(false)
        .addTypeAlias("int", "number")
        .addTypeAlias("bool", "boolean")
        );
}

#endif