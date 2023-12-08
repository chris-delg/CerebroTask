#include <iostream>
#include "../include/User.hpp"
using namespace std;

User::User()
{
    userId = "";
    userName = "";
    password = "";
}

User::User(string name, string id, string password)
{
    this->userId = id;
    this->userName = name;
    this->password = password;
}

string User::getUsername() const
{
    return this->userName;
}

string User::getId() const
{
    return this->userId;
}

string User::getPassword() const
{
    return this->password;
}

void User::setUsername(string username)
{
    this->userName = username;
}

void User::setId(string userId)
{
    this->userId = userId;
}

void User::setPassword(string password)
{
    this->password = password;
}

Task* User::getTasks(){
    return this->tasks;
}
