#ifndef GAME_LOGGER_H
#define GAME_LOGGER_H

#include "MessageInterface.h"
#include "LoggerInterface.h"

class TerminalLogger: public LoggerInterface{
public:
    TerminalLogger();
    void MakeLog(MessageInterface&) override;
};



#endif //GAME_LOGGER_H
