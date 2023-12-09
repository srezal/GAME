#ifndef GAME_GAME_H
#define GAME_GAME_H


#include <iostream>
#include "../Characters/PlayerManager.h"
#include "../Field/Field.h"
#include "../IO/Printer.h"
#include "../Field/FieldCreator.h"
#include "LevelType.h"
#include "../Field/LightController.h"
#include "../IO/InputManagerInterface.h"
#include <map>
#include "CommandsEnum.h"
#include "../Config/Config.h"
#include "CommandManager.h"


class Game{
private:
    Config& conf;
public:
    Game(Config&);
    void StartGame();
    void RestartGame();
    void EndGame();    
};


#endif //GAME_GAME_H
