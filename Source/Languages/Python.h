#ifndef _GLSC_SOURCE_LANGUAGES_PYTHON_
#define _GLSC_SOURCE_LANGUAGES_PYTHON_

#include "../GLSC.h"
#include "../Language.h"

using namespace std;

void GLSC::RegisterPython() {
    RegisterLanguage(Language()
        .setName("Python")
        .setExtension("py")
        .setPrintFunction("print")
        .setSemiColon("")
        .setClassConstructorName("def __init__")
        .setClassEnd("}")
        .setClassFunctionsTakeThis(true)
        .setClassFunctionsThis("self")
        .setClassNew("new")
        .setClassPrivacy(false)
        .setClassStartLeft("class ")
        .setClassStartRight(":")
        .setClassThis("this")
        .setClassThisAccess(".")
        .setCommentorBlockStart("\"\"\"")
        .setCommentorBlockEnd("\"\"\"")
        .setCommentorInline("#")
        .setConditionStartLeft(" ")
        .setConditionStartRight(":")
        .setConditionContinueLeft(" ")
        .setConditionContinueRight(":")
        .setConditionEnd("")
        .setFunctionDefine("def")
        .setFunctionDefineRight(":")
        .setFunctionDefineEnd("")
        .setRangedForLoops(true)
        .setFunctionReturnsExplicit(false)
        .setVariableTypesExplicit(false)
        .setVariableDeclare("")
    );
}

#endif