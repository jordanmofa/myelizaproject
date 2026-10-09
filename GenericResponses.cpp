#include "GenericResponses.h"

#include <regex>
#include <string>
#include <vector>

using namespace std;

struct GenericRule {
    regex pattern;
    string response;
};

// Removes spaces from the beginning and end of text.
static string trimText(const string& text) {
    return regex_replace(text, regex(R"(^\s+|\s+$)"), "");
}

// Changes a few pronouns so part of the user's sentence can be reused.
static string reflectStatement(const string& text) {
    string result = " " + trimText(text) + " ";

    result = regex_replace(result, regex(R"(\bmy\b)", regex_constants::icase), "your");
    result = regex_replace(result, regex(R"(\bme\b)", regex_constants::icase), "you");
    result = regex_replace(result, regex(R"(\bi am\b)", regex_constants::icase), "you are");
    result = regex_replace(result, regex(R"(\bi'm\b)", regex_constants::icase), "you are");
    result = regex_replace(result, regex(R"(\bi\b)", regex_constants::icase), "you");
    result = regex_replace(result, regex(R"(\byour\b)", regex_constants::icase), "my");
    result = regex_replace(result, regex(R"(\byou\b)", regex_constants::icase), "I");

    return trimText(result);
}

bool getGenericResponse(const string& input, string& response) {
    smatch match;

    // These rules cover common verbs and short answers.
    const vector<GenericRule> rules = {
        {regex(R"(\b(have|has|had)\b)", regex_constants::icase),
         "Why is having that important to you?"},
        {regex(R"(\b(purchase|buy|bought)\b)", regex_constants::icase),
         "What made you want to purchase that?"},
        {regex(R"(\b(travel|trip|vacation|visit)\b)", regex_constants::icase),
         "How do you feel when you think about traveling?"},
        {regex(R"(\b(know|knew|understand)\b)", regex_constants::icase),
         "What makes you feel sure about that?"},
        {regex(R"(\b(learn|learned|learning)\b)", regex_constants::icase),
         "What would you like to learn from that experience?"},
        {regex(R"(\b(work|job|career)\b)", regex_constants::icase),
         "How does work affect the way you feel?"},
        {regex(R"(\b(want|wanted|need)\b)", regex_constants::icase),
         "Why do you feel that you need that?"},
        {regex(R"(\b(think|thought|believe)\b)", regex_constants::icase),
         "What led you to think that?"},
        {regex(R"(\b(can't|cannot|unable)\b)", regex_constants::icase),
         "What do you think is stopping you?"},
        {regex(R"(\b(always|never)\b)", regex_constants::icase),
         "Can you think of a specific time when that happened?"},
        {regex(R"(^\s*(yes|yeah|yep|sure)\s*[.!?]*$)", regex_constants::icase),
         "You sound certain. What makes you feel that way?"},
        {regex(R"(^\s*(no|nope|not really)\s*[.!?]*$)", regex_constants::icase),
         "Why do you disagree?"},
        {regex(R"(^\s*(maybe|possibly|i don't know|idk)\s*[.!?]*$)", regex_constants::icase),
         "What part are you unsure about?"},
        {regex(R"(\bbecause\b)", regex_constants::icase),
         "Is that the main reason?"},
        {regex(R"(\bremember\b)", regex_constants::icase),
         "What does that memory mean to you?"}
    };

    for (const GenericRule& rule : rules) {
        if (regex_search(input, rule.pattern)) {
            response = rule.response;
            return true;
        }
    }

    // regex_match checks the whole sentence and regex_replace helps reuse the answer.
    regex feelingPattern(R"(^\s*i feel\s+(.+)$)", regex_constants::icase);
    if (regex_match(input, match, feelingPattern)) {
        response = "What makes you feel " + reflectStatement(match[1].str()) + "?";
        return true;
    }

    return false;
}
