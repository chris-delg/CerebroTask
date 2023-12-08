#include "../include/OpenaiAPI.hpp"
#include "../openai/openai.hpp"
#include <iostream>
#include <string>

using namespace std;

// Constructor
OpenaiAPI::OpenaiAPI() {
    this->apiKey = "";
    this->prompt = "";
    this->output = "";
}

// Member functions 
void OpenaiAPI::setApiKey(){
    if(this->apiKey != ""){
        return;
    }

    string key = "";
    cout << "Enter your API key : ";
    cin >> key;
    this->apiKey = key;
}

void OpenaiAPI::setPrompt(string newPrompt) {
    this->prompt = newPrompt;
}

string OpenaiAPI::getOutput() {
    if(apiKey == ""){
        cout << "No API key found" << endl;
        return "";
    }

    if(prompt == ""){
        cout << "No prompt was found" << endl;
        return "";
    }
    
    openai::start(apiKey);
    
    openai::Json jsonRequest;
    jsonRequest["model"] = "gpt-3.5-turbo";
    jsonRequest["messages"][0]["role"] = "user";
    jsonRequest["messages"][0]["content"] = prompt;
    jsonRequest["max_tokens"] = 4000;
    jsonRequest["temperature"] = 0;

    auto chat = openai::chat().create(jsonRequest);

    return chat["choices"][0]["message"]["content"].get<string>();;
}
