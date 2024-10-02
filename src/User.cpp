#include "../includes/User.h"


int User::setAccountInfo(std::string username, std::string password, std::string email, std::string userIdVal) 
    {   
        this -> username = username;
        this -> password = password;
        this -> email = email;
        this -> userID = userIdVal;
        this -> deposit = 0;
        return 0;
    }

std::string User::getUsername () {
    return this -> username;
}

std::unordered_map <std::string, std::string> User::getAccountInfo () {
        std::unordered_map <std::string, std::string> userInfo;
        std::string path = "../programfiles/userData/" + this -> username + ".txt";
        
        std::ifstream userdata(path);
        if (userdata.is_open()) {
            std::vector <std::string> mas;
            std::string line;
            while (std::getline(userdata, line)) {
                mas.push_back(line);
            }

            std::string userStocks = "";
            int counter = 1;
            if (mas.size() > 6) {
                for (size_t i = 6; i < mas.size(); i++) {
                    userStocks += std::to_string(counter) + "." + mas[i] + "; ";
                    counter++;
                }
                userInfo["User stocks"] = userStocks;
            } else {
                userInfo["User stocks"] = "No stocks in portfolio now";
            }
            userInfo["Email"] = mas[2];
            userInfo["Username"] = mas[0];
        }
        return userInfo;
}
