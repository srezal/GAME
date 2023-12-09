#ifndef GAME_TERMINALINPUTMANAGER_H
#define GAME_TERMINALINPUTMANAGER_H


#include "InputManagerInterface.h"


class TerminalInputManager: public InputManagerInterface{
public:
    TerminalInputManager();
    char GetChar() override;
    std::string GetString() override;
    ~TerminalInputManager() override;
};


#endif //GAME_TERMINALINPUTMANAGER_H