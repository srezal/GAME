#ifndef GAME_TELEPORTEVENT_H
#define GAME_TELEPORTEVENT_H


#include "../Characters/PlayerManager.h"
#include "../Utils/Vector.h"
#include "EventInterface.h"
#include "EventVisitorInterface.h"


class TeleportEvent: public EventInterface{
public:
    TeleportEvent();
    EventInterface* copy() override;
    void action(PlayerManager& player_manager) override;
    void AcceptVisitor(EventVisitorInterface&) override;
    ~TeleportEvent() override;
};


#endif //GAME_TELEPORTEVENT_H