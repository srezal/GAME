#ifndef GAME_ACTIONMANAGER_H
#define GAME_ACTIONMANAGER_H


#include "../Field/Field.h"
#include "../Characters/PlayerManager.h"
#include "../Game/GameState.h"
#include "../IO/Printer.h"
#include "../Config/Config.h"
#include "../Field/Field.h"
#include "../Characters/Player.h"
#include "../Game/CommandsEnum.h"
#include "../Game/CommandManager.h"


class ActionManager{
private:
    CommandManager command_manager;
    Config& conf;
    PlayerManager& pm;
    Field& field;
    Player& player;
    Printer* printer;
    bool player_mooved;
    bool exit;
public:
    ActionManager(Config&, PlayerManager&, Field&, Player&);
    void RunCommand(CommandsEnum);
    GameState GameIteration();
    ~ActionManager();
};


#endif //GAME_ACTIONMANAGER_H