#ifndef _GLSC_SOURCE_GLSC_CPP_
#define _GLSC_SOURCE_GLSC_CPP_

#include <algorithm> 
#include <climits>
#include <cctype>
#include <fstream>
#include <functional> 
#include <iostream>
#include <string>
#include <thread>

#include "glsc.h"

using namespace std;

GLSC::GLSC() {
    Languages = {};

    SearchEnds = {
        { ' ', ' ' },
        { '{', '}' },
        { '(', ')' }
    };
}

void GLSC::ConvertFile(const string& fileName, const vector<string>& languageNames) const {
    ifstream input;
    vector<string> lines;
    vector<thread> threads;
    string line;

    input.open(fileName + ".gls");
    if (!input) {
        cerr << "Error opening " << fileName << ".gls for reading." << endl;
        return;
    }

    lines.resize(0);
    while (getline(input, line)) {
        lines.push_back(line);
    }

    for (const auto& languageName : languageNames) {
        threads.push_back(thread(GLSC::ConvertFileThreaded, *this, FileConversionArguments(fileName, lines, Languages.at(languageName))));
    }

    for (auto& thread : threads) {
        thread.join();
    }

    input.close();
}

void GLSC::ConvertFileThreaded(const FileConversionArguments arguments) const {
    ConvertFile(arguments.fileName, arguments.lines, arguments.language);
}

void GLSC::ConvertFile(const string& fileName, const vector<string>& lines, const Language& language) const {
    ofstream output;
    output.open(fileName + "." + language.Extension());

    if (!output) {
        cerr << "Error opening " << output << "." << language.Extension() << " for writing." << endl;
        return;
    }

    output << ParseCommands(language, lines) << endl;
    output.close();
}

string GLSC::ParseCommands(const string& language, const vector<string>& commandsRaw) const {
    return ParseCommands(Languages.at(language), commandsRaw);
}

string GLSC::ParseCommands(const Language& language, const vector<string>& commandsRaw) const {
    string output = "";
    pair<string, int> command;
    int numTabs = 0;
    size_t i;

    // Minimizes the amount of resizes the string will have to do later on...
    output.reserve(commandsRaw.size() * 7);

    // The first line will never start with a newline, or be initially tabbed
    try {
        command = ParseCommand(language, commandsRaw[0], false);
        // The first character seems to be skipped. Not sure why...
        output += " " + command.first;
        numTabs += command.second;
    }
    catch (const char* error) {
        output += "!!!!!!! " + string(error) + " !!!!!!!";
    }

    // The rest of the commands all might have different tabbings
    for (i = 1; i < commandsRaw.size(); i += 1) {
        try {
            command = ParseCommand(language, commandsRaw[i], false);
        }
        catch (const char* error) {
            cout << "Got an error!" << endl;
            output += "\n" + generateTabs(numTabs) + "!!!!!!! " + error + " !!!!!!!";
            continue;
        }

        if (command.second == INT_MIN) {
            output += " " + command.first;
        }
        else if (command.second < 0) {
            numTabs += command.second;
            if (command.first.size() != 0) {
                output += "\n" + generateTabs(numTabs) + command.first;
            }
        }
        else {
            output += "\n" + generateTabs(numTabs) + command.first;
            numTabs += command.second;
        }
    }

    return output.substr(1);
}

pair<string, int> GLSC::ParseCommand(const string& language, const string& commandRaw, bool isInline = false) const {
    return ParseCommand(Languages.at(language), commandRaw, isInline);
}

pair<string, int> GLSC::ParseCommand(const Language& language, const string& commandRaw, bool isInline = false) const {
    pair<string, int> output = { "", 0 };

    if (CommandIsBlank(commandRaw)) {
        return output;
    }

    pair<string, int> result;
    vector<string> arguments;
    string function, argumentsRaw;
    size_t colonIndex;

    colonIndex = commandRaw.find(':');

    if (colonIndex != string::npos) {
        function = trim(commandRaw.substr(0, colonIndex));
        argumentsRaw = trim(commandRaw.substr(colonIndex + 1));
        arguments = ParseArguments(language, argumentsRaw, isInline);
    }
    else {
        function = trim(commandRaw);
    }

    output = language.Print(function, arguments, isInline);

    return output;
}

vector<string> GLSC::ParseArguments(const string& language, const string& argumentsRaw, bool isInline = false) const {
    return ParseArguments(Languages.at(language), argumentsRaw, isInline);
}

vector<string> GLSC::ParseArguments(const Language& language, const string& argumentsRaw, bool isInline = false) const {
    vector<string> arguments;
    string argument;
    size_t i, end;

    for (i = 0; i < argumentsRaw.size(); i += 1) {
        const char& starter = argumentsRaw[i];

        if (isspace(starter)) {
            continue;
        }

        if (starter == '{' || starter == '(') {
            end = FindSearchEnd(argumentsRaw, starter, i);
            i += 1;
        }
        else {
            end = FindNextSpace(argumentsRaw, i);
        }

        argument = argumentsRaw.substr(i, end - i);

        // Not yet tested!
        if (starter == '{') {
            argument = ParseCommand(language, argument, true).first;
        }

        arguments.push_back(argument);
        i = end;
    }

    return arguments;
}

void GLSC::RegisterLanguage(const string language) {
    if (language == "Python") {
        RegisterPython();
        return;
    }

    if (language == "TypeScript") {
        RegisterTypeScript();
        return;
    }

    if (language == "CPlusPlus") {
        RegisterCPlusPlus();
        return;
    }
}

void GLSC::RegisterLanguage(Language language) {
    if (Languages.find(language.Name()) != Languages.end()) {
        throw language.Name() + " already exists in GLSC.";
    }

    Languages[language.Name()] = language;
}

const Language& GLSC::getLanguage(const string name) const {
    return Languages.find(name)->second;
}

inline string GLSC::generateTabs(const size_t numTabs) const {
    return string(numTabs * 4, ' ');
}

size_t GLSC::FindNextSpace(const string& haystack, const size_t start) const {
    for (size_t i = start + 1; i < haystack.size(); i += 1) {
        if (isspace(haystack[i])) {
            return i;
        }
    }

    return haystack.size();
}

bool GLSC::CommandIsBlank(const string& command) const {
    return std::all_of(command.begin(), command.end(), [](char i) {
        return isspace(i);
    });
}

size_t GLSC::FindSearchEnd(const string& haystack, const char& searcher, const size_t start) const {
    size_t i;
    size_t numStarts = 1;
    const char& ender = SearchEnds.find(searcher)->second;

    for (i = start + 1; i < haystack.size(); i += 1) {
        const char& current = haystack[i];

        if (current == searcher) {
            numStarts += 1;
        }
        else if (current == ender) {
            numStarts -= 1;
            if (numStarts < 1) {
                return i;
            }
        }
    }

    return string::npos;
}

// Trim commands graciously donated by http://stackoverflow.com/a/217605/1830407

string GLSC::ltrim(string s) const {
    s.erase(s.begin(), find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace))));
    return s;
}

string GLSC::rtrim(string s) const {
    s.erase(find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(), s.end());
    return s;
}

string GLSC::trim(string s) const {
    return ltrim(rtrim(s));
}

size_t GLSC::IndexOfAny(const string& haystack, const vector<char>& needles, size_t start = 0) const {
    size_t i, j;

    for (i = start; i < haystack.size(); i += 1) {
        for (j = 0; j < needles.size(); j += 1) {
            if (haystack[i] == needles[j]) {
                return i;
            }
        }
    }

    return string::npos;
}

#endif