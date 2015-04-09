#ifndef _GLSC_MAIN_CPP_
#define _GLSC_MAIN_CPP_

#include <cstdlib>
#include <iostream>
#include <string>

#include "glsc.h"
#include "Languages/JavaScript.h"

int main(int argc, char* argv[]) {
    GLSC tester;
    
    tester.RegisterJavaScript();

    std::cout << tester.getLanguage("JavaScript").Name() << endl;

    vector<string> arguments = { "Hello world!" };
    std::cout << tester.getLanguage("JavaScript").CommentBlock(arguments).first;

    return EXIT_SUCCESS;
}

#endif