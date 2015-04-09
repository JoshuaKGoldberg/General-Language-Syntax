#ifndef _GLSC_SOURCE_LANGUAGES_PYTHON_
#define _GLSC_SOURCE_LANGUAGES_PYTHON_

#include "../GLSC.h"
#include "../Language.h"

using namespace std;

void GLSC::RegisterPython() {
    RegisterLanguage(Language()
        .setName("Python")
        .setPrintFunction("print")
    );
}

#endif