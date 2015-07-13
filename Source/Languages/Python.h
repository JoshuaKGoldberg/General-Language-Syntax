#ifndef _GLSC_SOURCE_LANGUAGES_PYTHON_
#define _GLSC_SOURCE_LANGUAGES_PYTHON_

#include "../GLSC.h"
#include "../Language.h"

using namespace std;

void GLSC::RegisterPython() {
    RegisterLanguage(Language()
        .setName("Python")
        .setExtension("py")
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
        .setPrintAsKeyword(true)
        .setPrintFunction("print")
        .setRangedForLoops(true)
        .setFunctionReturnsExplicit(false)
        .setVariableTypesExplicit(false)
        .setVariableDeclare("")
        .addValueAlias("False", "false")
        .addValueAlias("True", "true")
    );
}

#endif