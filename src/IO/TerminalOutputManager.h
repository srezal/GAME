#ifndef GAME_TERMINALOUTPUTMANAGER_H
#define GAME_TERMINALOUTPUTMANAGER_H


#include "OutputManagerInterface.h"


class TerminalOutputManager: public OutputManagerInterface{
public:
    void sendMsg(std::string) override;
    ~TerminalOutputManager() override;
};


#endif //GAME_TERMINALOUTPUTMANAGER_H