#ifndef GAME_FILEINPUTMANAGER_H
#define GAME_FILEINPUTMANAGER_H


#include "InputManagerInterface.h"
#include "../IO/FileOpenModes.h"
#include "../IO/FileManager.h"
#include "../Utils/StringParser.h"


#define CONTROL_TXT_PATH "/home/srezal/study/GAME/src/control.txt"


class FileInputManager: public InputManagerInterface{
private:
    FileManager file_manager;
public:
    FileInputManager();
    char GetChar() override;
    std::string GetString() override;
    ~FileInputManager() override;
};


#endif //GAME_FILEINPUTMANAGER_H