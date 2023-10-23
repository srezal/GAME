#include "PickUpCoinEvent.h"


PickUpCoinEvent::PickUpCoinEvent(PlayerManager& player_manager, unsigned int coin_denomination):
    player_manager(player_manager), coin_denomination(coin_denomination), icon('$'){

}


EventInterface* PickUpCoinEvent::copy(){
    return new PickUpCoinEvent(player_manager, coin_denomination);
}


void PickUpCoinEvent::action(){
    player_manager.addScore(coin_denomination);
}


bool PickUpCoinEvent::is_finite(){
    return true;
}


char PickUpCoinEvent::getIcon(){
    return icon;
}


PickUpCoinEvent::~PickUpCoinEvent(){}