#ifndef GAME_GAME_H
#define GAME_GAME_H


#include <iostream>
#include "PlayerManager.h"
#include "Field.h"
#include "Printer.h"
#include "FieldCreator.h"
#include "LevelType.h"
#include "LightController.h"
#include "KeyListenerInterface.h"
#include "Commands/PlayerCommandInterface.h"


class Game{
private:
    LevelType level_type;
    KeyListenerInterface* key_listener_ptr;
public:
    Game();
    void StartGame();
    void SetLevel_type();
    void ChangeKeyListener();
    PlayerCommandInterface* GetCommand();
    void ExitLevel();
    ~Game();
};


#endif //GAME_GAME_H
