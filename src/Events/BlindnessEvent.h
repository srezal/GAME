#ifndef GAME_BLINDNESSEVENT_H
#define GAME_BLINDNESSEVENT_H


#include "EventInterface.h"
#include "../PlayerManager.h"
#include "../EventVisitorInterface.h"


class BlindnessEvent: public EventInterface{
    EventInterface* copy() override;
    void action(PlayerManager& player_manager) override;
    void AcceptVisitor(EventVisitorInterface&) override;
    ~BlindnessEvent() override;
};


#endif //GAME_BLINDNESSEVENT_H