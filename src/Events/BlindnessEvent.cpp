#include "BlindnessEvent.h"


EventInterface* BlindnessEvent::copy(){
    return new BlindnessEvent();
}


void BlindnessEvent::action(PlayerManager& player_manager){
    player_manager.DecreaseVision(2);
}


void BlindnessEvent::AcceptVisitor(EventVisitorInterface& visitor){
    visitor.visit(*this); // Superhard to understand single line of code 
}


BlindnessEvent::~BlindnessEvent(){}