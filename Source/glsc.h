#ifndef _GLSC_SOURCE_GLSC_H_
#define _GLSC_SOURCE_GLSC_H_

#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

#include "language.h"

using namespace std;

class GLSC {
public:
    GLSC();
    ~GLSC() { }

    string ParseCommands(const string& language, const vector<string>& commandsRaw) const;
    pair<string, int> ParseCommand(const string& language, const string& commandsRaw, const bool isInline) const;
    vector<string> ParseArguments(const string& language, const string& argumentsRaw, const bool isInline) const;

    void RegisterLanguage(Language language);
    const Language& getLanguage(const string name) const;
    void RegisterJavaScript();
    void RegisterPython();

protected:
    inline string generateTabs(const size_t numTabs) const;
    bool CommandIsBlank(const string& command) const;
    size_t FindNextSpace(const string& haystack, const size_t start) const;
    size_t FindSearchEnd(const string& haystack, const char& searcher, const size_t start) const;
    std::string ltrim(string s) const;
    std::string rtrim(string s) const;
    std::string trim(string s) const;
    size_t IndexOfAny(const string& haystack, const vector<char>& needles, size_t start) const;

private:
    unordered_map<string, Language> Languages;
    unordered_map<char, char> SearchEnds;
};

#include "glsc.cpp"

#endif