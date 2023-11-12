#include "PlayerGoUpCommand.h"
#include "../Direction.h"


void PlayerGoUpCommand::Run(PlayerManager& player_manager){
    player_manager.changeCoord(Direction::UP);
}


PlayerGoUpCommand::~PlayerGoUpCommand(){}