#ifndef GAME_PLAYERGOLEFTCOMMAND_H
#define GAME_PLAYERGOLEFTCOMMAND_H


#include "PlayerCommandInterface.h"
#include "../PlayerManager.h"


class PlayerGoLeftCommand:  public PlayerCommandInterface{
public:
    void Run(PlayerManager& player_manager) override;
    ~PlayerGoLeftCommand() override; 
};


#endif //GAME_PLAYERGOLEFTCOMMAND_H