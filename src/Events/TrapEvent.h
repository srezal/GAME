#ifndef GAME_TRAPEVENT_H
#define GAME_TRAPEVENT_H


#include "../Characters/PlayerManager.h"
#include "EventInterface.h"
#include "EventVisitorInterface.h"


class TrapEvent: public EventInterface{
private:
    unsigned int damage_size;
public:
    TrapEvent(unsigned int damage_size);
    EventInterface* copy() override;
    void action(PlayerManager& player_manager) override;
    void AcceptVisitor(EventVisitorInterface&) override;
    ~TrapEvent() override;
};


#endif //GAME_TRAPEVENT_H