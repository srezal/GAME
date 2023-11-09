#include "PickUpKeyEvent.h"


EventInterface* PickUpKeyEvent::copy(){
    return new PickUpKeyEvent();
}


void PickUpKeyEvent::action(PlayerManager& player_manager){
    player_manager.setHas_key(1);
}


void PickUpKeyEvent::AcceptVisitor(EventVisitorInterface& visitor){
    visitor.visit(*this); // Superhard to understand single line of code 
}


PickUpKeyEvent::~PickUpKeyEvent(){}