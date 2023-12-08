#ifndef PAGE_HPP
#define PAGE_HPP

#include <iostream>
#include <string>
using namespace std;


class Page {
    private:
        string main_text[10];
        string options_text[10];
    public:
        virtual void printPageMainText() = 0;
        virtual void printPageOptions() = 0;
        virtual void printPageInputError() = 0;
        virtual string getLine(int line, int text) = 0;
};

#endif /* PAGE_HPP */