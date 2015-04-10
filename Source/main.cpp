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
        "",
        "comment line : Start of a while loop",
        "while condition start : x < 7",
        "    print line : \"Lana!\"",
        "    comment inline : \"Lana!\"",
        "while end",
        "",
        "for numbers start : i int 0 lessthan 7 increase 1", // for... not implemented
        "    print line : {operation number : i plus 1}", // {} not implemented
        "for end",
        "",
        "if condition start : 7 lessthan 14",
        "    print line : \"Yay!\"",
        "if end",
        "",
        "comment block : (and a bleeble) (and a blabble) (and a) (that's all folks!)"
    });

    return EXIT_SUCCESS;
}

#endif