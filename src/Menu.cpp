#include "../includes/Menu.h"


int Menu::RunStartMenu()
    {
        std::cout << "_______________________" << std::endl;
        std::cout << "|   You are welcome!  |" << std::endl;
        std::cout << "|      1.Log in       |" << std::endl;
        std::cout << "|      2.Sign up      |" << std::endl;
        std::cout << "|---------------------|" << std::endl;
        
        int choice; 
        std::cin >> choice;
        if (choice == 1) {
            LogRegSystem runSystem;
            runSystem.Entrance();
        } else if (choice == 2) {
            LogRegSystem runSystem;
            runSystem.SignUp();
        }

        return 0;
    }