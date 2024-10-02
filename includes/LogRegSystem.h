#ifndef REGSYSTEM_H
#define REGSYSTEM_H

#include <iostream>
#include <fstream>
#include <vector>
#include <string>

#define SLASH_LINE "--------------------------------------"

class LogRegSystem {
public:
    int Entrance();
    long long genRandomID();
    int SignUp();
};

#endif