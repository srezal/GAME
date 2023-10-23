#ifndef GAME_PICKUPCOINEVENT_H
#define GAME_PICKUPCOINEVENT_H


#include "EventInterface.h"
#include "PlayerManager.h"


class PickUpCoinEvent: public EventInterface{
private:
    unsigned int coin_denomination;
    PlayerManager& player_manager;
    char icon;
public:
    PickUpCoinEvent(PlayerManager& player_manager, unsigned int coin_denomination);
    EventInterface* copy() override;
    void action() override;
    char getIcon() override;
    bool is_finite() override;
    ~PickUpCoinEvent() override;
};


#endif //GAME_PICKUPCOINEVENT_H