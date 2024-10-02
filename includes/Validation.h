#ifndef VALIDATION_H
#define VALIDATION_H

#include <string>
#include <iostream>

class Validation {
public:
    bool isValidUsername(std::string username);
    bool isValidEmail(std::string email);
    bool isValidPassword(std::string password);
    bool isValidCreditCardNumber(std::string number);
    bool isValidPhoneNumber(std::string number);
};


#endif 