#ifndef GAME_PICKUPKEYEVENT_H
#define GAME_PICKUPKEYEVENT_H


#include "EventInterface.h"
#include "../PlayerManager.h"
#include "../EventVisitorInterface.h"


class PickUpKeyEvent: public EventInterface{
    EventInterface* copy() override;
    void action(PlayerManager& player_manager) override;
    void AcceptVisitor(EventVisitorInterface&) override;
    ~PickUpKeyEvent() override;
};


#endif //GAME_PICKUPKEYEVENT_H