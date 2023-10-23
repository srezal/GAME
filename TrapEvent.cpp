#include "TrapEvent.h"


TrapEvent::TrapEvent(PlayerManager& player_manager, unsigned int damage_size):
    player_manager(player_manager), damage_size(damage_size), icon('x'){

}


EventInterface* TrapEvent::copy(){
    return new TrapEvent(player_manager, damage_size);
}


void TrapEvent::action(){
    player_manager.addHealth(-damage_size);
}


bool TrapEvent::is_finite(){
    return true;
}


char TrapEvent::getIcon(){
    return icon;
}


TrapEvent::~TrapEvent(){}