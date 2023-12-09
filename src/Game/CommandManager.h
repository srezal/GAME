#ifndef GAME_COMMANDMANAGER_H
#define GAME_COMMANDMANAGER_H


#include "CommandsEnum.h"
#include "../Config/Config.h"
#include <vector>


class CommandManager{
public:
    CommandsEnum GetCommand(Config&, char&);
    void SetDefaultKeyBindings(Config&);
    void SetCommandFromSplittedString(Config&, std::vector<std::string>&);
    void CheckCommandsKeys(Config& conf);
};


#endif //GAME_COMMANDMANAGER_H