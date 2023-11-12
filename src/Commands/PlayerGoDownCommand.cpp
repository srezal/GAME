#include "PlayerGoDownCommand.h"
#include "../Direction.h"


void PlayerGoDownCommand::Run(PlayerManager& player_manager){
    player_manager.changeCoord(Direction::DOWN);
}


PlayerGoDownCommand::~PlayerGoDownCommand(){}