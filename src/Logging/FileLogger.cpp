#include "FileLogger.h"



FileLogger::FileLogger(){
    out.open(LOGS_TXT_PATH);
}


void FileLogger::MakeLog(MessageInterface& imsg){
    out << imsg << "\n";
}