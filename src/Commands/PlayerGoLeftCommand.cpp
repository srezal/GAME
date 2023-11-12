#include "PlayerGoLeftCommand.h"
#include "../Direction.h"


void PlayerGoLeftCommand::Run(PlayerManager& player_manager){
    player_manager.changeCoord(Direction::LEFT);
}


PlayerGoLeftCommand::~PlayerGoLeftCommand(){}