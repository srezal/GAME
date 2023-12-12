#include "TerminalLogger.h"
#include <iostream>


TerminalLogger::TerminalLogger(){}


void TerminalLogger::MakeLog(MessageInterface& msg_interface){
    std::cout << msg_interface << "\n";
}