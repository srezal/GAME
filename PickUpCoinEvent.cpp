#include "PickUpCoinEvent.h"


PickUpCoinEvent::PickUpCoinEvent(unsigned int coin_denomination):
    coin_denomination(coin_denomination){
        
    }


EventInterface* PickUpCoinEvent::copy(){
    return new PickUpCoinEvent(coin_denomination);
}


void PickUpCoinEvent::action(PlayerManager& player_manager){
    player_manager.addScore(coin_denomination);
}


void PickUpCoinEvent::AcceptVisitor(EventVisitorInterface& visitor){
    visitor.visit(*this); // Superhard to understand single line of code 
}


PickUpCoinEvent::~PickUpCoinEvent(){}