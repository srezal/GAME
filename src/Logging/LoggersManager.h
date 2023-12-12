#ifndef GAME_LOGGERSMANAGER_H
#define GAME_LOGGERSMANAGER_H


#include <vector>
#include "LoggerInterface.h"
#include "MessageInterface.h"


class LoggersManager{
private:
    std::vector<LoggerInterface*> loggers_vector;
public:
    void AddLogger(LoggerInterface*);
    void MakeLog(MessageInterface&);
    ~LoggersManager();
};


#endif //GAME_LOGGERSMANAGER_H
