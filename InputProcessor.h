#ifndef INPUTPROCESSOR_H
#define INPUTPROCESSOR_H

#include <map>
#include <string>

class InputProcessor {
public:
    std::string normalize(const std::string& input) const;
    bool isExitCommand(const std::string& input) const;
    bool isRepeated(const std::string& input);
    int getResponseCount(const std::string& input) const;

private:
    std::map<std::string, int> responseHistory;
};

#endif
