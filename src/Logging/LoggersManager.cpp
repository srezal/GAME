#include "LoggersManager.h"


void LoggersManager::AddLogger(LoggerInterface* ilogger){
    loggers_vector.push_back(ilogger);
}


void LoggersManager::MakeLog(MessageInterface& imsg){
    for(auto logger_ptr: loggers_vector) logger_ptr->MakeLog(imsg);
}


LoggersManager::~LoggersManager(){
    for(auto logger_ptr: loggers_vector) delete logger_ptr;
}