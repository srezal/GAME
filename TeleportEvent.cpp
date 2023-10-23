#include "TeleportEvent.h"


TeleportEvent::TeleportEvent(PlayerManager& player_manager, Vector coords):
    player_manager(player_manager), coords(coords), icon('?'){

}


EventInterface* TeleportEvent::copy(){
    return new TeleportEvent(player_manager, coords);
}


void TeleportEvent::action(){
    player_manager.setCoord(coords);
}


bool TeleportEvent::is_finite(){
    return false;
}


char TeleportEvent::getIcon(){
    return icon;
}


TeleportEvent::~TeleportEvent(){}