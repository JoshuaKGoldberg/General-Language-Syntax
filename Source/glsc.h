#ifndef _GLSC_SOURCE_GLSC_H_
#define _GLSC_SOURCE_GLSC_H_

#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

#include "language.h"

using namespace std;

struct FileConversionArguments {
    FileConversionArguments(const string fileNameIn, const vector<string> linesIn, const Language languageIn)
        : fileName(fileNameIn), lines(linesIn), language(languageIn)
    { }
    ~FileConversionArguments() { }

    const string fileName;
    const vector<string> lines;
    const Language language;
};

class GLSC {
public:
    GLSC();
    ~GLSC() { }

    void ConvertFile(const string& fileName, const vector<string>& languageNames) const;
    void ConvertFileThreaded(const FileConversionArguments arguments) const;
    void ConvertFile(const string& fileName, const vector<string>& input, const Language& language) const;

    string ParseCommands(const string& language, const vector<string>& commandsRaw) const;
    string ParseCommands(const Language& language, const vector<string>& commandsRaw) const;
    pair<string, int> ParseCommand(const string& language, const string& commandsRaw, const bool isInline) const;
    pair<string, int> ParseCommand(const Language& language, const string& commandsRaw, const bool isInline) const;
    string ParseCommandOutput(const pair<string, int> &command, int numTabs) const;
    vector<string> ParseArguments(const string& language, const string& argumentsRaw, const bool isInline) const;
    vector<string> ParseArguments(const Language& language, const string& argumentsRaw, const bool isInline) const;

    void RegisterLanguage(const string language);
    void RegisterLanguage(Language language);
    const Language& getLanguage(const string name) const;
    void RegisterCSharp();
    void RegisterPython();
    void RegisterTypeScript();

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