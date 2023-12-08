#ifndef USER_HPP
#define USER_HPP

#include "../include/Task.hpp"

#include <string>

using namespace std;

class User
{
private:
    string userId;
    string userName;
    string password;
    Task tasks[50];

public:
    User();
    User(string, string, string);
    string getUsername() const;
    string getId() const;
    string getPassword() const;
    void setUsername(string username);
    void setId(string userId);
    void setPassword(string password);
    Task* getTasks();
};

#endif