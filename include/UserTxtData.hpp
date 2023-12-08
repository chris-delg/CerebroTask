#ifndef USERTXTDATA_HPP
#define USERTXTDATA_HPP

#include "../include/UserData.hpp"

#include <fstream>
#include <string>

using namespace std;

class UserTxtData : public UserData{
    private:
        ofstream writeTxt;
        ifstream readTxt;

    public:  
        void writeData(string fileName);
        void readData(string fileName);
};

#endif