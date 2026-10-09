#include "InputProcessor.h"
#include "ResponseManager.h"

#include <iostream>
#include <string>

using namespace std;

int main() {
    InputProcessor inputProcessor;
    ResponseManager responseManager;
    string userInput;

    cout << "ELIZA: Hello. I am here to listen." << endl;
    cout << "ELIZA: Type \"bye\" when you want to end the conversation." << endl;

    while (true) {
        cout << "\nYou: ";
        getline(cin, userInput);

        // Stops safely if the input stream closes.
        if (!cin) {
            cout << "\nELIZA: Goodbye." << endl;
            break;
        }

        string cleanedInput = inputProcessor.normalize(userInput);

        if (cleanedInput.empty()) {
            cout << "ELIZA: Please enter a response." << endl;
            continue;
        }

        if (inputProcessor.isExitCommand(cleanedInput)) {
            cout << "ELIZA: Goodbye. Thank you for talking with me." << endl;
            break;
        }

        if (inputProcessor.isRepeated(cleanedInput)) {
            cout << "ELIZA: You already gave that response. Please tell me something different." << endl;
            continue;
        }

        cout << "ELIZA: " << responseManager.createResponse(cleanedInput) << endl;
    }

    return 0;
}
