#ifndef TRADINGAPP_H
#define TRADINGAPP_H


#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <unordered_map>

#include "User.h"
#include "Logger.h"
#include "Validation.h"
#include "Stock.h"

#define SLASH_LINE "--------------------------------------"

class TradingApp {
private:
    User currentUser;
public:
    int SetUser(User NewUser);
    int RunMainMenu (User CurUser);
    int GetAccountInfo (User NewUser);
    int depositMoney(User NewUser);
    int BuyStocks(User NewUser);
    int SellStocks (User NewUser);
    int checkTransactions(User NewUser);
};

#endif