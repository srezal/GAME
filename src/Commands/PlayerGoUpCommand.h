#ifndef GAME_PLAYERGOUPCOMMAND_H
#define GAME_PLAYERGOUPCOMMAND_H


#include "PlayerCommandInterface.h"
#include "../PlayerManager.h"


class PlayerGoUpCommand:  public PlayerCommandInterface{
public:
    void Run(PlayerManager& player_manager) override;
    ~PlayerGoUpCommand() override;
};


#endif //GAME_PLAYERGOUPCOMMAND_H