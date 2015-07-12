#ifndef _GLSC_MAIN_CPP_
#define _GLSC_MAIN_CPP_

#include <cstdlib>
#include <cstring>
#include <iostream>
#include <string>

#include "glsc.h"
#include "Languages/CSharp.h"
#include "Languages/Python.h"
#include "Languages/TypeScript.h"

string StripFilename(const string& fileName);
void PrintHelp();

int main(int argc, char* argv[]) {
    if (argc == 1 || strcmp(argv[1], "help") == 0) {
        PrintHelp();
        return EXIT_SUCCESS;
    }

    GLSC converter;

    vector<string> inputFiles;
    vector<string> languages;
    string outputDirectory = ".";

    for (int i = 1; i < argc; i += 1) {
        if (argv[i][0] == '-') {
            switch (argv[i][1]) {
            case 'l':
                converter.RegisterLanguage(argv[i + 1]);
                languages.push_back(argv[i + 1]);
                break;
            case 'd':
                outputDirectory = argv[i + 1];
                break;
            }
            i += 1;
        }
        else {
            inputFiles.push_back(StripFilename(argv[i]));
        }
    }

    for (const auto& inputFile : inputFiles) {
        converter.ConvertFile(inputFile, languages);
    }

    return EXIT_SUCCESS;
}

string StripFilename(const string& fileName) {
    if (fileName.find(".gls") == string::npos) {
        return fileName;
    }

    return fileName.substr(0, fileName.find(".gls"));
}

void PrintHelp() {
    cout << endl;
    cout << "General Language Syntax Compiler (GLSC) Version 0.1" << endl;
    cout << "2015 - Josh Goldberg" << endl;
    cout << "A compiler for a general language syntax that can be mapped 1-1 to common languages like TypeScript or Python." << endl;
    cout << endl;
    cout << "Usage:" << endl;
    cout << "    glsc <file1> <file2> <file3> ... [-l <language>] [-d <directory>]" << endl;
    cout << endl;
    cout << "Examples:" << endl;
    cout << "    glsc source.gls -l Python" << endl;
    cout << "    glsc one.gls two.gls three.gls -l TypeScript -l Python" << endl;
    cout << "    glsc -l Python -d path/to/results main.gls" << endl;
    cout << endl;
}

#endif