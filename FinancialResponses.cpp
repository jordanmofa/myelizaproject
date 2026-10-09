#include "FinancialResponses.h"

#include <regex>
#include <string>
#include <vector>

using namespace std;

struct FinancialRule {
    regex pattern;
    string response;
};

bool getFinancialResponse(const string& input, string& response) {
    const vector<FinancialRule> rules = {
        {regex(R"(\b(money|cash|funds)\b)", regex_constants::icase),
         "How is money affecting your current situation?"},
        {regex(R"(\b(save|saving|savings)\b)", regex_constants::icase),
         "What are you hoping to save for?"},
        {regex(R"(\b(invest|investment|stocks|crypto)\b)", regex_constants::icase),
         "How comfortable are you with the risk involved?"},
        {regex(R"(\b(debt|loan|owe)\b)", regex_constants::icase),
         "How has that debt been affecting you?"},
        {regex(R"(\b(bankruptcy|bankrupt)\b)", regex_constants::icase),
         "What concerns you most about that financial problem?"},
        {regex(R"(\b(bill|bills|rent|mortgage)\b)", regex_constants::icase),
         "Which expense is causing the most pressure?"},
        {regex(R"(\b(salary|paycheck|income|wage)\b)", regex_constants::icase),
         "How do you feel about your current income?"},
        {regex(R"(\b(expensive|afford|cost)\b)", regex_constants::icase),
         "What choices are you considering because of the cost?"}
    };

    for (const FinancialRule& rule : rules) {
        if (regex_search(input, rule.pattern)) {
            response = rule.response;
            return true;
        }
    }

    return false;
}
