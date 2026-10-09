#include "ResponseManager.h"

#include "ConcernResponses.h"
#include "EducationResponses.h"
#include "EntertainmentResponses.h"
#include "FinancialResponses.h"
#include "GenericResponses.h"
#include "RelationshipResponses.h"
#include "WellbeingResponses.h"

using namespace std;

// Checks the serious topics first, then the other conversation categories.
string ResponseManager::createResponse(const string& input) const {
    string response;

    if (getConcernResponse(input, response)) {
        return response;
    }

    if (getRelationshipResponse(input, response)) {
        return response;
    }

    if (getFinancialResponse(input, response)) {
        return response;
    }

    if (getWellbeingResponse(input, response)) {
        return response;
    }

    if (getEducationResponse(input, response)) {
        return response;
    }

    if (getEntertainmentResponse(input, response)) {
        return response;
    }

    if (getGenericResponse(input, response)) {
        return response;
    }

    // A default response is returned when no pattern is found.
    return "Please tell me more about that.";
}
