#ifndef GAME_LOGGERINTERFACE_H
#define GAME_LOGGERINTERFACE_H


#include "MessageInterface.h"


class LoggerInterface{
public:
    virtual void MakeLog(MessageInterface&) {}
    virtual ~LoggerInterface(){}
};


#endif //GAME_LOGGERINTERFACE_H