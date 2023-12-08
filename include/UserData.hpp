#ifndef USERDATA_HPP
#define USERDATA_HPP

#include "../include/User.hpp"

#include <unordered_map>
#include <string>

using namespace std;

class UserData{
    protected:
        User *user;
        unordered_map<string, string> loginInfo;

    public: 
        void setUser(User *u);
        User* getUser();
        unordered_map<string, string> getLoginMap();
        virtual void writeData(string fileName) = 0;
        virtual void readData(string fileName) = 0;
};

#endif