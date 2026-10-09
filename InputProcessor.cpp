#include "InputProcessor.h"

#include <algorithm>
#include <cctype>
#include <regex>

using namespace std;

// Removes extra spaces and converts the input to lowercase.
string InputProcessor::normalize(const string& input) const {
    string cleaned = regex_replace(input, regex(R"(\s+)"), " ");

    while (!cleaned.empty() && isspace(static_cast<unsigned char>(cleaned.front()))) {
        cleaned.erase(cleaned.begin());
    }

    while (!cleaned.empty() && isspace(static_cast<unsigned char>(cleaned.back()))) {
        cleaned.pop_back();
    }

    transform(cleaned.begin(), cleaned.end(), cleaned.begin(),
              [](unsigned char c) { return static_cast<char>(tolower(c)); });

    return cleaned;
}

// regex_match is used because the whole input must be the word "bye".
bool InputProcessor::isExitCommand(const string& input) const {
    return regex_match(input, regex(R"(^bye[.!?]*$)", regex_constants::icase));
}

// Stores each answer and returns true when it has already been entered.
bool InputProcessor::isRepeated(const string& input) {
    int& count = responseHistory[input];
    count++;
    return count > 1;
}

int InputProcessor::getResponseCount(const string& input) const {
    auto found = responseHistory.find(input);

    if (found == responseHistory.end()) {
        return 0;
    }

    return found->second;
}
