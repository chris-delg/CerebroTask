#ifndef USERBINDATA_HPP
#define USERBINDATA_HPP

#include "UserData.hpp"

#include <fstream>
#include <string>

using namespace std;

class UserBinData : public UserData{
    private:
        ofstream writeBin;
        ifstream readBin;

    public:  
        virtual void writeData(string fileName);
        virtual void readData(string fileName);
};

#endif