#include "TeleportEvent.h"


TeleportEvent::TeleportEvent(Vector coords):
    coords(coords){
}


EventInterface* TeleportEvent::copy(){
    return new TeleportEvent(coords);
}


void TeleportEvent::action(PlayerManager& player_manager){
    player_manager.setCoord(coords);
}


void TeleportEvent::AcceptVisitor(EventVisitorInterface& visitor){
    visitor.visit(*this); // Superhard to understand single line of code 
}


TeleportEvent::~TeleportEvent(){}