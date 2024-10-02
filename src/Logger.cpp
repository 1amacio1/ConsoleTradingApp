#include "../includes/Logger.h"



int Logger::makeLog(std::string user, std::string funcName) {
    std::ifstream userInpLogs("../programfiles/userData/" + user + ".log");
        std::vector <std::string> mas;
        std::string line;
        while (std::getline(userInpLogs, line)) {
            mas.push_back(line);
        }
        userInpLogs.close();

        std::time_t current_time = std::time(nullptr);
        char buffer[100];
        std::strftime(buffer, sizeof(buffer), "%Y-%m-%d %H:%M:%S", std::localtime(&current_time));
        std::string operationTime = std::string(buffer);
        
        mas.push_back(funcName + " " + operationTime);

        std::ofstream userOutLogs("../programfiles/userData/" + user + ".log");
        for (size_t i = 0; i < mas.size(); i++) {
            userOutLogs << mas[i] << std::endl;    
        }
        return 0;
}

// int Logger::updateLogs(std::string user, int num) {
//         std::ifstream inpFile("../programfiles/userData/" + user + ".log");
//         std::vector <std::string> mas;
//         std::string line;
//         while (std::getline(inpFile, line)) {
//             mas.push_back(line);
//         }
//         if (mas.size() >= 15){
//             for (size_t i = 1; i <= num; i++) {
//                 mas.erase(mas.begin() + i);
//             }

//             std::ofstream outFile("../programfiles/userData/" + user + ".log");
//             for (size_t i = 0; i < mas.size(); i++) {
//                 outFile << mas[i] << std::endl;
//         }
//         }
//     return 0;
//     }