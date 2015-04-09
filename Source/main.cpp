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

    cout << tester.ParseCommands("JavaScript", {
        "print line : (\"Hello world!\")",
        "variable declare : x int 7",
        "while condition start : x < 7",
        "print line : \"Lana!\"",
        "while condition end : "
    });

    return EXIT_SUCCESS;
}

#endif