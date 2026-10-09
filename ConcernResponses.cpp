#include "ConcernResponses.h"

#include <regex>
#include <string>
#include <vector>

using namespace std;

struct ConcernRule {
    regex pattern;
    string response;
};

bool getConcernResponse(const string& input, string& response) {
    const vector<ConcernRule> rules = {
        {regex(R"(\b(suicide|suicidal|kill myself|end my life)\b)", regex_constants::icase),
         "Your safety matters. Please contact emergency services or a trusted person right now."},
        {regex(R"(\b(kill|hurt someone|harm someone)\b)", regex_constants::icase),
         "That sounds serious. Please step away from the situation and contact emergency help or someone you trust."},
        {regex(R"(\b(hate|hated)\b)", regex_constants::icase),
         "What is causing such a strong feeling?"},
        {regex(R"(\b(angry|mad|furious)\b)", regex_constants::icase),
         "What usually happens when you feel this angry?"},
        {regex(R"(\b(depressed|depression|hopeless)\b)", regex_constants::icase),
         "How long have you been feeling this way?"},
        {regex(R"(\b(anxiety|anxious|panic)\b)", regex_constants::icase),
         "What situations seem to increase your anxiety?"},
        {regex(R"(\b(stress|stressed|overwhelmed)\b)", regex_constants::icase),
         "What is causing the most stress right now?"},
        {regex(R"(\b(afraid|scared|fear)\b)", regex_constants::icase),
         "What are you most afraid might happen?"},
        {regex(R"(\b(cry|crying|cried)\b)", regex_constants::icase),
         "What was going through your mind when you started crying?"},
        {regex(R"(\b(unsafe|in danger|threatened)\b)", regex_constants::icase),
         "Please move to a safe place and contact someone who can help you immediately."}
    };

    for (const ConcernRule& rule : rules) {
        if (regex_search(input, rule.pattern)) {
            response = rule.response;
            return true;
        }
    }

    return false;
}
