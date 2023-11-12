#ifndef GAME_PLAYERGODOWNCOMMAND_H
#define GAME_PLAYERGODOWNCOMMAND_H


#include "PlayerCommandInterface.h"
#include "../PlayerManager.h"


class PlayerGoDownCommand:  public PlayerCommandInterface{
public:
    void Run(PlayerManager& player_manager) override;
    ~PlayerGoDownCommand() override;
};


#endif //GAME_PLAYERGODOWNCOMMAND_H