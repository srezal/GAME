#ifndef GAME_SHOWEXITEVENTS_H
#define GAME_SHOWEXITEVENTS_H


#include "EventInterface.h"
#include "../PlayerManager.h"
#include "../EventVisitorInterface.h"


class ShowExitEvent: public EventInterface{
    EventInterface* copy() override;
    void action(PlayerManager& player_manager) override;
    void AcceptVisitor(EventVisitorInterface&) override;
    ~ShowExitEvent() override;
};


#endif //GAME_SHOWEXITEVENTS_H