#ifndef GAME_CONFIG_H
#define GAME_CONFIG_H


#include "../IO/InputManagerInterface.h"
#include "../IO/OutputManagerInterface.h"
#include "../Game/LevelType.h"
#include "../Game/CommandsEnum.h"
#include "../Logging/LoggersManager.h"
#include <map>
#include <vector>



#define SETTING_TXT_PATH "/home/srezal/study/GAME/src/settings.txt"

class Config{
public:
    InputManagerInterface* INPUT_MANAGER_PTR;
    OutputManagerInterface* OUTPUT_MANAGER_PTR;
    LoggersManager loggers_manager;
    LevelType LEVEL_TYPE;
    std::map<char, CommandsEnum> COMMANDS_KEYS;
    std::map<CommandsEnum, std::string> commands_strings;


    Config();
    void SetInputManager();
    void SetOutputManager();
    void SetLevelType();
    void ReadControlSettingsFromFile();
    void SetTerminalLogger();
    void SetFileLogger();
    ~Config();
};


#endif //GAME_CONFIG_H