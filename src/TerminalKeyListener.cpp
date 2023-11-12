#include "TerminalKeyListener.h"
#include <iostream>


TerminalKeyListener::TerminalKeyListener(){}


char TerminalKeyListener::ReadChar(){
    system("stty raw");
    char key;
    std::cin >> key;
    system("stty cooked");
    return key;
}


std::string TerminalKeyListener::ReadString(){
    std::string str;
    std::getline(std::cin, str);
    return str;
}