#include "WellbeingResponses.h"

#include <regex>
#include <string>
#include <vector>

using namespace std;

struct WellbeingRule {
    regex pattern;
    string response;
};

bool getWellbeingResponse(const string& input, string& response) {
    const vector<WellbeingRule> rules = {
        {regex(R"(\b(exercise|workout|gym|running)\b)", regex_constants::icase),
         "How does exercise affect your mood?"},
        {regex(R"(\b(vitamin|vitamins|supplement)\b)", regex_constants::icase),
         "What made you start thinking about vitamins?"},
        {regex(R"(\b(sleep|sleeping|insomnia)\b)", regex_constants::icase),
         "How has your sleep been lately?"},
        {regex(R"(\b(tired|exhausted|fatigue)\b)", regex_constants::icase),
         "When do you notice the tiredness the most?"},
        {regex(R"(\b(relax|relaxing|calm|meditate)\b)", regex_constants::icase),
         "What usually helps you relax?"},
        {regex(R"(\b(healthy|health|wellness)\b)", regex_constants::icase),
         "What part of your health would you like to improve?"},
        {regex(R"(\b(eat|eating|food|diet)\b)", regex_constants::icase),
         "How do your eating habits affect the way you feel?"},
        {regex(R"(\b(sick|ill|pain|hurting)\b)", regex_constants::icase),
         "How long have you been dealing with that discomfort?"}
    };

    for (const WellbeingRule& rule : rules) {
        if (regex_search(input, rule.pattern)) {
            response = rule.response;
            return true;
        }
    }

    return false;
}
