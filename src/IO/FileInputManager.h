#ifndef GAME_FILEINPUTMANAGER_H
#define GAME_FILEINPUTMANAGER_H


#include <fstream>
#include "InputManagerInterface.h"
#include "../Utils/StringParser.h"


#define CONTROL_TXT_PATH "/home/srezal/study/GAME/src/control.txt"


class FileInputManager: public InputManagerInterface{
private:
    std::ifstream input;
public:
    FileInputManager();
    char GetChar() override;
    std::string GetString() override;
    ~FileInputManager() override;
};


#endif //GAME_FILEINPUTMANAGER_H