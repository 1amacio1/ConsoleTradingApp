#ifndef LOGGER_H
#define LOGGER_H

#include <string>
#include <fstream>
#include <vector>
#include <ctime>


class Logger {
public:
    int makeLog (std::string user, std::string funcName);
    // int updateLogs(std::string user, int num);
};

#endif