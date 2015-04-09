#ifndef _GLSC_MAIN_CPP_
#define _GLSC_MAIN_CPP_

#include <cstdlib>
#include <iostream>
#include <string>

#include "glsc.h"
#include "Languages/JavaScript.h"
#include "Languages/Python.h"

int main(int argc, char* argv[]) {
    GLSC tester;
    
    tester.RegisterJavaScript();
    tester.RegisterPython();

    cout << tester.ParseCommands("Python", {
        "print line : (\"Hello world!\")",
        "variable declare : x int 7"
    });

    return EXIT_SUCCESS;
}

#endif