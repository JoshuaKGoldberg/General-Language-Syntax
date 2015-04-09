#ifndef _GLSC_SOURCE_GLSC_H_
#define _GLSC_SOURCE_GLSC_H_

#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

class GLSC {
public:
    GLSC();
    ~GLSC() { }

    string ParseCommands(const vector<string>& commandsRaw) const;
    pair<string, int> ParseCommand(const string& commandsRaw) const;
    vector<string> ParseArguments(const string& argumentsRaw) const;

    static RegisterLanguage(Language& language);

protected:
    size_t FindNextSpace(const string& haystack, const size_t start) const;
    size_t FindSearchEnd(const string& haystack, const char& searcher, const size_t start) const;
    std::string ltrim(string s) const;
    std::string rtrim(string s) const;
    std::string trim(string s) const;
    size_t IndexOfAny(const string& haystack, const vector<char>& needles, size_t start) const;

private:
    vector<char> SearchStarts;
    unordered_map<char, char> SearchEnds;
};

#include "glsc.cpp"

#endif