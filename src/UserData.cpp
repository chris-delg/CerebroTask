#include "../include/UserData.hpp"

#include <string>
#include <unordered_map>

using namespace std;

void UserData::setUser(User *u){
    this->user = u;
    loginInfo[user->getUsername()] = user->getPassword();
}

unordered_map<string, string> UserData::getLoginMap(){
    return loginInfo;
}

User* UserData::getUser(){
    return user;
}
