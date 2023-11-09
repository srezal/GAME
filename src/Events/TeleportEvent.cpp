#include "TeleportEvent.h"


TeleportEvent::TeleportEvent(){}


EventInterface* TeleportEvent::copy(){
    return new TeleportEvent();
}


void TeleportEvent::action(PlayerManager& player_manager){
    player_manager.tpPlayerToStartPosition();
}


void TeleportEvent::AcceptVisitor(EventVisitorInterface& visitor){
    visitor.visit(*this); // Superhard to understand single line of code 
}


TeleportEvent::~TeleportEvent(){}