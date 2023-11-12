#include "PlayerGoRightCommand.h"
#include "../Direction.h"


void PlayerGoRightCommand::Run(PlayerManager& player_manager){
    player_manager.changeCoord(Direction::RIGHT);
}


PlayerGoRightCommand::~PlayerGoRightCommand(){}