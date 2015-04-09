#ifndef _GLSC_MAIN_CPP_
#define _GLSC_MAIN_CPP_

#include <cstdlib>

#include "glsc.h"

int main(int argc, char* argv[]) {
    GLSC tester;

    vector<string> args = tester.ParseArguments(" abc defghi j (hello world) asdf (hurp durp)");

    for (const auto& arg : args) {
        cout << arg << endl;
    }

    return EXIT_SUCCESS;
}

#endif