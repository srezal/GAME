#include "TerminalInputManager.h"
#include <iostream>


TerminalInputManager::TerminalInputManager(){}


char TerminalInputManager::GetChar(){
    system("stty raw");
    char key;
    std::cin >> key;
    std::cout << "\b";
    system("stty cooked");
    return key;
}


std::string TerminalInputManager::GetString(){
    std::string str;
    std::getline(std::cin, str);
    return str;
}


TerminalInputManager::~TerminalInputManager(){}