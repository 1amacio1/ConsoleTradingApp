#ifndef STOCK_H
#define STOCK_H

#include <string>

class Stock
{
public:
    std::string stockName;
    std::string stockTiker;
    std::string stockPrice;
    
    int setStockInfo(std::string name, std::string tiker, std::string price);    
};


#endif