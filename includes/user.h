#ifndef USER_H
#define USER_H

#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
#include <fstream>

class User 
{
private:
    std::string username;
    std::string password;
    std::string email;
    std::string userID;
    unsigned int deposit;
public:
    int setAccountInfo(std::string username, std::string password, std::string email, std::string userIdVal);
    std::string getUsername ();
    std::unordered_map <std::string, std::string> getAccountInfo ();
};


#endif