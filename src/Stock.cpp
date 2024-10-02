#include "../includes/Stock.h"


int Stock::setStockInfo(std::string name, std::string tiker, std::string price) {
        this -> stockName = name;
        this -> stockTiker = tiker;
        this -> stockPrice = price;
        return 0;
    }