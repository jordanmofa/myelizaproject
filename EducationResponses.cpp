#include "EducationResponses.h"

#include <regex>
#include <string>
#include <vector>

using namespace std;

struct EducationRule {
    regex pattern;
    string response;
};

bool getEducationResponse(const string& input, string& response) {
    const vector<EducationRule> rules = {
        {regex(R"(\b(school|college|university|campus)\b)", regex_constants::icase),
         "How has school been affecting you lately?"},
        {regex(R"(\b(class|classes|course|courses)\b)", regex_constants::icase),
         "Which class is taking most of your attention?"},
        {regex(R"(\b(homework|assignment|project)\b)", regex_constants::icase),
         "What part of the assignment feels most difficult?"},
        {regex(R"(\b(exam|test|quiz|final)\b)", regex_constants::icase),
         "How are you preparing for the exam?"},
        {regex(R"(\b(study|studying|studied)\b)", regex_constants::icase),
         "What study method has worked best for you?"},
        {regex(R"(\b(professor|teacher|instructor)\b)", regex_constants::icase),
         "How would you describe your experience with that instructor?"},
        {regex(R"(\b(grade|grades|gpa)\b)", regex_constants::icase),
         "Why are those grades important to you?"},
        {regex(R"(\b(student|students|classmate)\b)", regex_constants::icase),
         "How do the other students affect your experience?"}
    };

    for (const EducationRule& rule : rules) {
        if (regex_search(input, rule.pattern)) {
            response = rule.response;
            return true;
        }
    }

    return false;
}
