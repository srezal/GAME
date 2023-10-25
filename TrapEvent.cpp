#include "TrapEvent.h"


TrapEvent::TrapEvent(unsigned int damage_size):
    damage_size(damage_size){

}


EventInterface* TrapEvent::copy(){
    return new TrapEvent(damage_size);
}


void TrapEvent::action(PlayerManager& player_manager){
    player_manager.addHealth(-damage_size);
}


void TrapEvent::AcceptVisitor(EventVisitorInterface& visitor){
    visitor.visit(*this); // Superhard to understand single line of code 
}


TrapEvent::~TrapEvent(){}