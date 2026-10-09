#include "EntertainmentResponses.h"

#include <regex>
#include <string>
#include <vector>

using namespace std;

struct EntertainmentRule {
    regex pattern;
    string response;
};

bool getEntertainmentResponse(const string& input, string& response) {
    const vector<EntertainmentRule> rules = {
        {regex(R"(\b(concert|festival|show)\b)", regex_constants::icase),
         "What did you enjoy most about the concert?"},
        {regex(R"(\b(movie|movies|film|cinema)\b)", regex_constants::icase),
         "What kind of movies do you connect with most?"},
        {regex(R"(\b(music|song|artist|album)\b)", regex_constants::icase),
         "How does that music make you feel?"},
        {regex(R"(\b(dance|dancing|club)\b)", regex_constants::icase),
         "What do you enjoy about dancing?"},
        {regex(R"(\b(restaurant|bar|cafe|dinner)\b)", regex_constants::icase),
         "What do you like about going there?"},
        {regex(R"(\b(game|games|gaming|video game)\b)", regex_constants::icase),
         "What keeps you interested in that game?"},
        {regex(R"(\b(sport|sports|football|basketball|soccer)\b)", regex_constants::icase),
         "What do you enjoy most about that sport?"},
        {regex(R"(\b(hobby|hobbies|fun|entertainment)\b)", regex_constants::icase),
         "How often do you make time for that activity?"}
    };

    for (const EntertainmentRule& rule : rules) {
        if (regex_search(input, rule.pattern)) {
            response = rule.response;
            return true;
        }
    }

    return false;
}
