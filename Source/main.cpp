#ifndef _GLSC_MAIN_CPP_
#define _GLSC_MAIN_CPP_

#include <cstdlib>
#include <iostream>

#include "glsc.h"
#include "Languages/JavaScript.h"

int main(int argc, char* argv[]) {
    GLSC tester;
    
    tester.RegisterJavaScript();

    std::cout << tester.getLanguage("JavaScript").Name() << endl;

    return EXIT_SUCCESS;
}

#endif