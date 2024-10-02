#include "../includes/Validation.h"

bool Validation::isValidUsername(std::string username) {
        bool flag = false;
        for (char c : username) {
            if (std::isdigit(c)) {
                flag = true;
                break;
            }
        }

        if (username.size() <= 10 && flag == true) {
            return true;
        }
        return false;
    }

    bool Validation::isValidEmail(std::string email) {
        const char symb = '@';
        int counter = 0;
        for (auto c : email) {
            if (c == symb) {
                counter++;
            }
        }
        if (counter == 1) {
            return true;
        }
        return false;
    }

    bool Validation::isValidPassword(std::string password) {
        int counter_dig = 0, counter_symbols = 0;
        const std::string special_symbols = "!#$%&'()*+,-./:;<=>?@[]^_`{|}~";
        for (auto cur : password) {
            if (special_symbols.find(cur) != std::string::npos) {
                counter_symbols++;
            } else if (std::isdigit(cur)) {
                counter_dig++;
            }
        }
        return counter_dig > 0 && counter_symbols > 0;
    }

    bool Validation::isValidCreditCardNumber (std::string number) {
        for (size_t i = 0; i < number.size(); i++) {
            if (number[i] >= 'A' && number[i] <= 'Z' || number[i] >= 'a' && number[i] <= 'z') {
                return false;
            } else if (number.size() != 13) {
                return false;
            } else {
                return true;
            }
        }
    }

    bool Validation::isValidPhoneNumber (std::string number) {
        bool flag = true;
        for (size_t i = 0; i < number.size(); i++) {
            if (number[i] >= 'A' && number[i] <= 'Z' || number[i] >= 'a' && number[i] <= 'z') {
                flag = false;
                return flag; 
            }
        }
        if (number[0] != '+') {
            flag = false;
            return flag;
        }
        return flag;
    }