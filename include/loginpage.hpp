#ifndef LOGINPAGE_HPP
#define LOGINPAGE_HPP

#include "page.hpp"
using namespace std;

class LoginPage : public Page {
    private:
        string main_text[10];
        string options_text[10];

        bool username_valid(string name);
    public:
        LoginPage();
        void printPageMainText();
        void printPageOptions();
        void printPageInputError();
        string getLine(int line, int text);
        
        void login(string &user, string &pass, istream& input = cin);
};

#endif /* LOGINPAGE_HPP */