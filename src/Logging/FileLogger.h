#ifndef GAME_FILELOGGER_H
#define GAME_FILELOGGER_H


#include "LoggerInterface.h"
#include <fstream>

#define LOGS_TXT_PATH "/home/srezal/study/GAME/src/logs.txt"


class FileLogger: public LoggerInterface{
private:
    std::ofstream out;
public:
    FileLogger();
    void MakeLog(MessageInterface&) override;
};


#endif //GAME_FILELOGGER_H