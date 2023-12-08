#ifndef OPEN_AI
#define OPEN_AI

#include <string>

using namespace std;

class OpenaiAPI {
private:
    // Private members (data and functions)
    string apiKey;
    string prompt;
    string output;

public:
    // Public members (data and functions)

    // Constructor
    OpenaiAPI();

    // Member functions
    void setApiKey();
    void setPrompt(string newPrompt);
    string getOutput();
};

#endif // OPEN_AI