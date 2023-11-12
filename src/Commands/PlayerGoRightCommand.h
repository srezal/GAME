#ifndef GAME_PLAYERGORIGHTCOMMAND_H
#define GAME_PLAYERGORIGHTCOMMAND_H


#include "PlayerCommandInterface.h"
#include "../PlayerManager.h"


class PlayerGoRightCommand:  public PlayerCommandInterface{
public:
    void Run(PlayerManager& player_manager) override;
    ~PlayerGoRightCommand() override;
};


#endif //GAME_PLAYERGORIGHTCOMMAND_H