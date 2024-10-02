#include "../includes/TradingApp.h"



int TradingApp::SetUser(User NewUser) {
        this -> currentUser = NewUser;
        return 0;
    }

int TradingApp::RunMainMenu (User CurUser) {
        SetUser(CurUser);
        std::cout << "|---------------------------------------|" << std::endl;
        std::cout << "|             !TRADING APP!             |" << std::endl;
        std::cout << "|_______________________________________|" << std::endl;
        std::cout << "|              Menu:                    |" << std::endl;
        std::cout << "|        1.Get account info             |" << std::endl;
        std::cout << "|        2.Buy stocks                   |" << std::endl;
        std::cout << "|        3.Sell stocks                  |" << std::endl;
        std::cout << "|        4.Top up your account          |" << std::endl;
        std::cout << "|        5.History of transactions      |" << std::endl;
        std::cout << "|        6.Exit                         |" << std::endl;
        std::cout << "|---------------------------------------|" << std::endl;


        int choice;
        std::cout << "Choose the point, please: ";
        std::cin >> choice;
        std::cout << std::endl;
        switch (choice) {
            case 1:
                GetAccountInfo(CurUser);
                break;
            case 2:
                BuyStocks(CurUser);
                break;
            case 3:
                SellStocks(CurUser);
                break;
            case 4:
                depositMoney(CurUser);
                break;
            case 5:
                checkTransactions(CurUser);
                break;
            case 6:
                std::cout << "Goodbye!" << std::endl;
                return 0;
            default:
                std::cout << "Here is no such point!" << std::endl;
                std::cout << std::endl;
                RunMainMenu(CurUser);
        }


        return 0;
    }


int TradingApp::GetAccountInfo (User NewUser) {
    std::unordered_map <std::string, std::string> UserInfo = NewUser.getAccountInfo();
    std::cout << SLASH_LINE << std::endl;
    std::cout << "Here is your account info: " << std::endl;
    for (auto it = UserInfo.begin(); it != UserInfo.end(); ++it) {
        std::cout << it->first + ": " << it->second << std::endl;
    }
    std::cout << SLASH_LINE << std::endl;
    std::cout << std::endl;

    Logger log;
    log.makeLog(NewUser.getUsername(), "GetAccountInfo");

    RunMainMenu(NewUser);
    return 0;
    }


int TradingApp::depositMoney(User NewUser) {
        int choose;
        std::cout << SLASH_LINE << std::endl;
        std::cout << "Select payment method please:" << std::endl;
        std::cout << "1.Credit card" << std::endl;
        std::cout << "2.Phone number" << std::endl;
        std::cout << SLASH_LINE << std::endl;
        std::cin >> choose;
        switch(choose) {
            case 1:
                {
                Validation Validator;
                std::string CCnumber;
                while (Validator.isValidCreditCardNumber(CCnumber) != true) {
                    std::cout << SLASH_LINE << std::endl;
                    std::cout << "Enter your credit card number:" << std::endl;
                    std::cout << SLASH_LINE << std::endl;
                    std::cin >> CCnumber;
                    std::cout << std::endl;
                }

                unsigned int amount;
                std::cout << "Enter the deposit amount:" << std::endl;
                std::cin >> amount;
                std::cout << SLASH_LINE << std::endl;
                std::cout << "Your deposit is succesfully updated!" << std::endl;
                std::cout << SLASH_LINE << std::endl;
                std::string path = "../programfiles/userData/" + NewUser.getUsername() + ".txt";
                std::ifstream inpFile(path);
                std::string acc;
                std::vector <std::string> lines;
                if (!inpFile.is_open()) {
                    std::cout << "Error while opening file..." << std::endl;

                    Logger log;
                    log.makeLog(NewUser.getUsername(), "depositError");

                    RunMainMenu(NewUser);
                    return 0;
                } else {
                    std::string line;
                    while (std::getline(inpFile, line)) {
                        lines.push_back(line);
                    }
                }
                inpFile.close();

                const int accountLine = 5;
                int res = std::stoi(lines[accountLine - 1]);
                res += amount;
                lines[accountLine - 1] = std::to_string(res);

                std::ofstream outFile(path);
                if (!outFile.is_open()) {
                    std::cout << "Error while opening file..." << std::endl;

                    Logger log;
                    log.makeLog(NewUser.getUsername(), "depositError");

                    RunMainMenu(NewUser);
                    return 0;
                } for (const auto& line : lines) {
                    outFile << line << std::endl;
                }
                outFile.close();

                Logger log;
                log.makeLog(NewUser.getUsername(), "depositAccount: " + std::to_string(amount));


                break;
                }
            case 2:
                {
                Validation Validator;
                std::string phoneNumber;
                while (Validator.isValidPhoneNumber(phoneNumber) != true) {
                    std::cout << "Enter your phone number, please:" << std::endl;
                    std::cin >> phoneNumber;
                }
                std::cout << std::endl;
                unsigned int amount;
                std::cout << "Enter the deposit amount:" << std::endl;
                std::cin >> amount;
                std::cout << "Your deposit is succesfully updated!" << std::endl;
                std::cout << std::endl;
                std::string path = "../programfiles/userData/" + NewUser.getUsername() + ".txt";
                std::ifstream inpFile(path);
                std::string acc;
                std::vector <std::string> lines;
                if (!inpFile.is_open()) {
                    std::cout << "Error while opening file..." << std::endl;

                    Logger log;
                    log.makeLog(NewUser.getUsername(), "depositError");

                    RunMainMenu(NewUser);
                    return 0;
                } else {
                    std::string line;
                    while (std::getline(inpFile, line)) {
                        lines.push_back(line);
                    }
                }
                inpFile.close();

                const int accountLine = 5;
                int res = std::stoi(lines[accountLine - 1]);
                res += amount;
                lines[accountLine - 1] = std::to_string(res);

                std::ofstream outFile(path);
                if (!outFile.is_open()) {
                    std::cout << "Error while opening file..." << std::endl;

                    Logger log;
                    log.makeLog(NewUser.getUsername(), "depositError");

                    RunMainMenu(NewUser);
                    return 0;
                } for (const auto& line : lines) {
                    outFile << line << std::endl;
                }
                outFile.close();

                Logger log;
                log.makeLog(NewUser.getUsername(), "depositAccount: " + std::to_string(amount));

                break;
                }
            default:
                std::cout << "Here is no such point!" << std::endl;
        }

        RunMainMenu(NewUser);
        return 0;
    }

int TradingApp::BuyStocks(User NewUser) {
            std::cout << SLASH_LINE << std::endl;
            std::cout << "What stocks do you want to buy?" << std::endl;
            std::cout << SLASH_LINE << std::endl;
            std::cout << std::endl;
            std::ifstream inpFile("../programfiles/stocksInfo/StockNames.txt");
            if (!inpFile.is_open()) {
                std::cout << "Error while loading stocks info..." << std::endl;

                Logger log;
                log.makeLog(NewUser.getUsername(), "BuyStocksError");
            } else {
                std::string stock;
                while (std::getline(inpFile, stock)) {
                    std::cout << stock << std::endl;
                }
                std::cout << std::endl;
                std::cout << SLASH_LINE << std::endl;
                std::cout << "Enter the stock name from the list here:" << std::endl;
                std::cout << SLASH_LINE << std::endl;
                std::string newStock;
                std::cin >> newStock;
                std::string path = "../programfiles/stocksInfo/" + newStock + ".txt";
                std::ifstream stockFile(path);
                Stock userStock;
                std::string stockName, stockTiker, stockPrice;
                stockFile >> stockName;
                stockFile >> stockTiker;
                stockFile >> stockPrice;
                userStock.setStockInfo(stockName, stockTiker, stockPrice);
                std::cout << std::endl;
                std::cout << SLASH_LINE << std::endl;
                std::cout << "Here is some info about this stock:" << std::endl;
                std::cout << "Name: " << stockName << std::endl;
                std::cout << "Tiker: " << stockTiker << std::endl;
                std::cout << "Price: " << stockPrice << std::endl;
                std::cout << SLASH_LINE << std::endl;
                std::cout << std::endl;
                std::cout << SLASH_LINE << std::endl;
                std::cout << "How much stocks you want to buy? Enter the number please:" << std::endl;
                std::cout << SLASH_LINE << std::endl;
                std::string stockNumber;
                std::cin >> stockNumber;
                std::ifstream userFile("../programfiles/userData/" + NewUser.getUsername() + ".txt");
                std::vector <std::string> lines;
                std::string line;
                while (std::getline(userFile, line)) {
                    lines.push_back(line);
                }
                userFile.close();
                std::ofstream outFile("../programfiles/userData/" + NewUser.getUsername() + ".txt");
                for (size_t i = 0; i < lines.size(); i++) {
                    outFile << lines[i] << std::endl;
                }
                unsigned int userAccount = std::stoi(lines[4]);
                if (std::stoi(stockPrice) * std::stoi(stockNumber) > userAccount) {
                    std::cout << SLASH_LINE << std::endl;
                    std::cout << "You have not enough money to buy so many stocks. Top up your balance, please." << std::endl;
                    std::cout << "Do you want to deposit money? Input yes or no, please." << std::endl;
                    std::cout << SLASH_LINE << std::endl;
                    std::string answear;
                    std::cin >> answear;
                    if (answear == "yes") {
                        depositMoney(NewUser);
                        RunMainMenu(NewUser);
                        return 0;
                    } else {
                        Logger log;
                        log.makeLog(NewUser.getUsername(), "NotEnoughMoneyToBuyStocks");
                        RunMainMenu(NewUser);
                        return 0;
                    }
                } else {
                    std::string path = "../programfiles/userData/" + NewUser.getUsername() + ".txt";
                    std::ifstream inFile(path);
                    std::vector <std::string> userLines;
                    std::string line;
                    while (std::getline(inFile, line)) {
                        userLines.push_back(line);
                    }
                    inFile.close();

                    std::string substring = stockTiker;
                    int k = std::stoi(userLines[4]) - std::stoi(stockPrice) * std::stoi(stockNumber);
                    userLines[4] = std::to_string(k);
                    bool flag = false;
                    for (size_t i = 0; i < userLines.size(); i++) {
                        if (userLines[i].find(substring) != std::string::npos) {
                            flag = true;
                            break;
                        }
                    }
                    if (flag == true) {
                        for (size_t i = 0; i < userLines.size(); i++) {
                            if (userLines[i].find(substring) != std::string::npos) {
                                std::istringstream iss(userLines[i]);
                                std::string stockName;
                                std::string stockTiker;
                                int num;
                                iss >> stockName >> stockTiker >> num;
                                num += std::stoi(stockNumber);
                                std::ostringstream oss;
                                oss << stockName << " " << stockTiker << " " << num;
                                std::string updatedStr = oss.str();
                                userLines[i] = updatedStr;
                                break;
                            } 
                        }
                    } else {
                        std::string newStock = stockName + " " + stockTiker + " " + stockNumber;
                        userLines.push_back(newStock);
                    }
                    std::ofstream outFile("../programfiles/userData/" + NewUser.getUsername() + ".txt");
                    for (auto cur : userLines) {
                        outFile << cur << std::endl;
                    }
                    std::cout << SLASH_LINE << std::endl;
                    std::cout << "Stocks are succesfully added to your portfolio" << std::endl;
                    std::cout << SLASH_LINE << std::endl;
                    std::cout << std::endl;
                    outFile.close();
                    
                    Logger log;
                    log.makeLog(NewUser.getUsername(), "StocksBought: " + newStock + " " + stockNumber);

                    RunMainMenu(NewUser);
                }
            }
    return 0;
}

int TradingApp::SellStocks (User NewUser) {
    std::cout << SLASH_LINE << std::endl;
    std::cout << "What stocks do you want to sell?" << std::endl;
    std::cout << SLASH_LINE << std::endl;
    std::cout << "Here is your stocks, put the stock name here:" << std::endl;
    std::cout << SLASH_LINE << std::endl;
    std::string path = "../programfiles/userData/" + NewUser.getUsername() + ".txt";
    std::ifstream inpFile(path);
    std::vector <std::string> userLines;
    std::string line;
    while (std::getline(inpFile, line)) {
        userLines.push_back(line);
    }
    inpFile.close();
    for (size_t i = 6; i < userLines.size(); ++i) {
        std::cout << userLines[i] << std::endl;
    }
    std::string stock;
    std::cin >> stock;
    std::ifstream stockInfoFile("../programfiles/stocksInfo/" + stock + ".txt");
    std::vector <std::string> stockData;
    std::string stockDataLine;
    while (std::getline(stockInfoFile, stockDataLine)) {
        stockData.push_back(stockDataLine);
    }
    stockInfoFile.close();

    int stockLine;
    for (size_t i = 0; i < userLines.size(); i++) {
        if (userLines[i].find(stock) != std::string::npos) {
            stockLine = i;
            break;
        }
    }
    std::cout << SLASH_LINE << std::endl;
    std::cout << "How much stocks you want to sell? Put the number here:" << std::endl;
    std::cout << SLASH_LINE << std::endl;
    int number;
    std::cin >> number;
    std::istringstream iss(userLines[stockLine]);
    std::string stockName;
    std::string stockTiker;
    int num;
    iss >> stockName >> stockTiker >> num;
    if (number > num) {
        std::cout << "You have not enough stocks to sell..." << std::endl;
        Logger log;
        log.makeLog(NewUser.getUsername(), "NotEnoughtStocksToSell");
        std::cout << std::endl;
        RunMainMenu(NewUser);
    } else {
        num -= number;
        if (num != 0) {
            std::ostringstream oss;
            oss << stockName << " " << stockTiker << " " << num;
            std::string updatedStr = oss.str();
            userLines[stockLine] = updatedStr;
        } else {
            userLines.erase(userLines.begin() + stockLine);
        }
        int k = std::stoi(userLines[4]) - number * std::stoi(stockData[stockData.size() - 1]);
        userLines[4] = std::to_string(k);
        std::ofstream updatedFile("../programfiles/userData/" + NewUser.getUsername() + ".txt");
        for (auto cur : userLines) {
            updatedFile << cur << std::endl;
        }
        std::cout << SLASH_LINE << std::endl;
        std::cout << "Stock are sold succesfully! Your account is updated." << std::endl;
        std::cout << SLASH_LINE << std::endl;
        std::cout << std::endl;

        Logger log;
        log.makeLog(NewUser.getUsername(), "SoldStocks: " + stock + " " + std::to_string(number));

        RunMainMenu(NewUser);
    }
    return 0;
}

int TradingApp::checkTransactions(User NewUser) {
    std::ifstream inpFile("../programfiles/userData/" + NewUser.getUsername() + ".log");
    std::vector <std::string> mas;
    std::string line;
    while (std::getline(inpFile, line)) {
        mas.push_back(line);
    }
    inpFile.close();
    std::vector <std::string> history;
    for (size_t i = 0; i < mas.size(); i++) {
        if (mas[i].find("depositAccount") != std::string::npos || mas[i].find("SoldStocks") != std::string::npos || mas[i].find("StocksBought") != std::string::npos) {
            if (history.size() < 5) {
                history.push_back(mas[i]);
            } else {
                break;
            }
        }
    }
    std::ofstream outFile("../programfiles/userData/" + NewUser.getUsername() + ".log");
    for (size_t i = 0; i < mas.size(); i++) {
        outFile << mas[i] << std::endl;
    }
    outFile.close();
    std::cout << SLASH_LINE << std::endl;
    std::cout << "Here is your 5 latest transactions: " << std::endl;
    std::cout << SLASH_LINE << std::endl;
    for (auto cur : history) {
        std::cout << cur << std::endl;
    }
    std::cout << SLASH_LINE << std::endl;

    RunMainMenu(NewUser);
    return 0;
}
