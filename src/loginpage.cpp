#include "../include/loginpage.hpp"
using namespace std;

LoginPage::LoginPage()
{
    main_text[0] = "Welcome to CerebroTask : The AI Assisted Task Scheduler\n";
    main_text[1] = "---\n";
    
    main_text[9] = "Input not recognized. Try again:\n";

    options_text[0] = "Login Options:\n";
    options_text[1] = "l - login\n";
    options_text[2] = "q - quit\n";
    options_text[3] = "Enter username: ";
    options_text[4] = "Enter password: ";
    options_text[5] = "Username can not have a space in it. Enter other username.\n";

    options_text[9] = "Goodbye.[login]\n\nShutting off program...\n";
};

bool LoginPage::username_valid(string name)
{
    for (int i = 0; i < name.size(); i++)
    {
        if (name.at(i) == ' ')
        {
            return false;
        }
    }
    return true;
}

void LoginPage::printPageMainText()
{
    for (int i = 0; i < 2; i++)
    {
        cout << main_text[i];
    }
};

void LoginPage::printPageOptions()
{
    for (int i = 0; i < 3; i++)
    {
        cout << options_text[i];
    }
};

void LoginPage::printPageInputError()
{
    cout << main_text[9];
};

string LoginPage::getLine(int line, int text)
{
    switch (text)
    {
    case 0: // main_text
        return main_text[line];
    case 1: // options_text
        return options_text[line];
    }
    return "";
};

void LoginPage::login(string &user, string &pass, istream& input) {
    cout << options_text[3];
    string temp;
    getline(input, temp);
    while (!username_valid(temp)) 

    {
        cout << options_text[5];
        cout << options_text[3];
        getline(input, temp); 
    }
    user = temp;
    cout << options_text[4];
    getline(input, temp);
    pass = temp;
    return;
};
