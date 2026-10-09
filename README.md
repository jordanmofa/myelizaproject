# Primitive AI Chatbot (ELIZA)


## Project Description

This project is a simple AI chatbot based on ELIZA. The chatbot uses C++ regular expressions to recognize patterns in user input and generate responses. The program simulates a conversation with a psychiatrist and continues until the user enters **"bye"**.

---

## Files Included

- `main.cpp`
- `InputProcessor.cpp`
- `InputProcessor.h`
- `ResponseManager.cpp`
- `ResponseManager.h`
- `GenericResponses.cpp`
- `GenericResponses.h`
- `RelationshipResponses.cpp`
- `RelationshipResponses.h`
- `ConcernResponses.cpp`
- `ConcernResponses.h`
- `FinancialResponses.cpp`
- `FinancialResponses.h`
- `WellbeingResponses.cpp`
- `WellbeingResponses.h`
- `EducationResponses.cpp`
- `EducationResponses.h`
- `EntertainmentResponses.cpp`
- `EntertainmentResponses.h`
- `README.md`

---

## How to Compile

Open a terminal in the project directory and run:

```bash
g++ -std=c++17 *.cpp -o chatbot
```

---

## How to Run

After compiling, run the program with:

```bash
./chatbot
```

---

## Requirements

- C++17 compiler
- Standard C++ libraries
- Uses the following libraries:
  - `<iostream>`
  - `<string>`
  - `<vector>`
  - `<map>`
  - `<regex>`

---

## Program Notes

- The program accepts natural language input from the user.
- Every user input receives a response.
- Previous responses are stored to detect repeated answers.
- The conversation ends when the user enters **"bye"**.
- The chatbot uses `regex_match()`, `regex_search()`, and `regex_replace()` to process user input and generate responses.
