#include "TerminalOutputManager.h"


#include <iostream>


void TerminalOutputManager::sendMsg(std::string msg_text){
    std::cout << msg_text << "\n";
}


TerminalOutputManager::~TerminalOutputManager(){}