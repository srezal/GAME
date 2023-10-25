#ifndef GAME_PICKUPCOINEVENT_H
#define GAME_PICKUPCOINEVENT_H


#include "EventInterface.h"
#include "PlayerManager.h"
#include "EventVisitorInterface.h"


class PickUpCoinEvent: public EventInterface{
private:
    unsigned int coin_denomination;
public:
    PickUpCoinEvent(unsigned int coin_denomination);
    EventInterface* copy() override;
    void action(PlayerManager& player_manager) override;
    void AcceptVisitor(EventVisitorInterface&) override;
    ~PickUpCoinEvent() override;
};


#endif //GAME_PICKUPCOINEVENT_H