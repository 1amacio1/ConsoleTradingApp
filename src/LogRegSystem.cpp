#include "../includes/LogRegSystem.h"
#include "../includes/User.h"
#include "../includes/TradingApp.h"
#include "../includes/Logger.h"


int LogRegSystem::Entrance() 
    {
    std::string inputLog;
        std::string inputPas;
        std::string inputEml;
        std::cout << SLASH_LINE << std::endl;
        std::cout << "Input your username, please:" << std::endl;
        std::cin >> inputLog;
        std::cout << "Input your password, please:" << std::endl;
        std::cin >> inputPas;
        std::cout << "Input your email, please:" << std::endl;
        std::cin >> inputEml;
        std::cout << SLASH_LINE << std::endl;
        
        std::string userData = "../programfiles/userData/" + inputLog + ".txt";

        std::ifstream userdata(userData);

        if (!userdata.is_open()) {
            std::cout << "Error, while opening files, sorry! May be your input login is wrong.";
            Entrance();
            return 0;
        } else {
            std::vector <std::string> userInf;
            std::string line;
            while (std::getline(userdata, line)) {
                userInf.push_back(line);
            }
            std::string correctLog = userInf[0];
            std::string correctPas = userInf[1];
            std::string correctEml = userInf[2];
            std::string userID = userInf[3];
            std::cout << std::endl;
            while ((inputLog != correctLog) || (inputPas != correctPas) || (inputEml != correctEml)) {
                std::cout << "Your input is wrong, try again!" << std::endl;
                std::cout << std::endl;

                std::cout << "Input your username, please:" << std::endl;
                std::cin >> inputLog;
                std::cout << "Input your password, please:" << std::endl;
                std::cin >> inputPas;
                std::cout << "Input your email, please:" << std::endl;
                std::cin >> inputEml;
            }
            std::cout << SLASH_LINE << std::endl;
            std::cout << "Correctly, welcome to your profile!" << std::endl;
            std::cout << SLASH_LINE << std::endl;
            std::cout << std::endl;

            User newUser;
            newUser.setAccountInfo(inputLog, inputPas, inputEml, userID);

            Logger log;
            log.makeLog(inputLog, inputLog + "_LoggedIn");
            TradingApp app;
            app.RunMainMenu(newUser);
        }
        return 0;
}

long long LogRegSystem::genRandomID () {
        std::srand(time(NULL));
        const long long minVal = 100000000000;
        const long long maxVal = 999999999999;
        return rand() % (maxVal - minVal) + minVal;
}

int LogRegSystem::SignUp() 
{   
    long long userID = genRandomID();
    std::string userLog, userPas, userEml;

    Validation Validator;
    while (Validator.isValidUsername(userLog) != true) {
        std::cout << "Input your username please (it needs at least 1 digit):" << std::endl;
        std::cin >> userLog;
    }
    std::cout << std::endl;

    while (Validator.isValidPassword(userPas) != true) {
        std::cout << "Input your password please (put at least 1 digit and 1 special sym):" << std::endl;
        std::cin >> userPas;
    }
    std::cout << std::endl;

    while (Validator.isValidEmail(userEml) != true) {
        std::cout << "Input your email please:" << std::endl;
        std::cin >> userEml;
    }
    std::cout << std::endl;
    std::string path = "../programfiles/userData/" + userLog + ".txt";
    std::fstream userData;
    userData.open(path, std::fstream::app);

    if (!userData.is_open())
    {   
        std::cout << "Error while opening file..." << std::endl;
    } else {
        std::ofstream userLogs("../programfiles/userData/" + userLog + ".log");
        userLogs.close();

        userData << userLog << std::endl;
        userData << userPas << std::endl;
        userData << userEml << std::endl;
        userData << std::to_string(userID) << std::endl;
        userData << std::to_string(0) << std::endl;
        userData << "------------" << std::endl;
        std::cout << "Your profile set up! Welcome to our app." << std::endl;

        Logger log;
        log.makeLog(userLog, userLog + "_SignedUp");
    }

return 0;

}