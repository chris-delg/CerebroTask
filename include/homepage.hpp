#ifndef HOMEPAGE_HPP
#define HOMEPAGE_HPP

#include "page.hpp"
#include "OpenaiAPI.hpp"
using namespace std;

class HomePage : public Page
{
private:
    string main_text[10];
    string options_text[10];
    int curr_task = 0;
    OpenaiAPI ai;

public:
    HomePage();
    void printPageMainText();
    void printPageOptions();
    void printPageInputError();
    string getLine(int line, int text);

    void changeTask(int new_task);
    int getCurrTask() { return curr_task; };
    void printEditTask(string &new_details, string &new_date, /* int &new_priority,*/ istream &input = cin); // cin/input is done this way to facillitate gtest
    void printCreateTask(string &taskDetails, string &taskDueDate, int &taskPriority, istream &input = cin);
    void printAIResponse(string task);
};

#endif /* HOMEPAGE_HPP */