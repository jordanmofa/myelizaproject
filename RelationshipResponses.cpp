#include "RelationshipResponses.h"

#include <regex>
#include <string>
#include <vector>

using namespace std;

struct RelationshipRule {
    regex pattern;
    string response;
};

bool getRelationshipResponse(const string& input, string& response) {
    const vector<RelationshipRule> rules = {
        {regex(R"(\blove\b)", regex_constants::icase),
         "What does love mean to you in this situation?"},
        {regex(R"(\b(boyfriend|girlfriend|partner)\b)", regex_constants::icase),
         "How would you describe the relationship with your partner?"},
        {regex(R"(\b(husband|wife|spouse)\b)", regex_constants::icase),
         "What has been happening in the marriage?"},
        {regex(R"(\b(marriage|married|wedding)\b)", regex_constants::icase),
         "How do you feel about marriage?"},
        {regex(R"(\b(friend|friends|friendship)\b)", regex_constants::icase),
         "What do you value most in that friendship?"},
        {regex(R"(\b(mother|mom|mama)\b)", regex_constants::icase),
         "How would you describe your relationship with your mother?"},
        {regex(R"(\b(father|dad|papa)\b)", regex_constants::icase),
         "How would you describe your relationship with your father?"},
        {regex(R"(\b(family|parents|sibling|brother|sister)\b)", regex_constants::icase),
         "How does your family affect this situation?"},
        {regex(R"(\b(breakup|broke up|separated|divorce)\b)", regex_constants::icase),
         "What has been the hardest part of that separation?"},
        {regex(R"(\b(lonely|alone|miss someone)\b)", regex_constants::icase),
         "When do you feel the most alone?"}
    };

    for (const RelationshipRule& rule : rules) {
        if (regex_search(input, rule.pattern)) {
            response = rule.response;
            return true;
        }
    }

    return false;
}
