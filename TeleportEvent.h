#ifndef GAME_TELEPORTEVENT_H
#define GAME_TELEPORTEVENT_H


#include "EventInterface.h"
#include "PlayerManager.h"
#include "Vector.h"


class TeleportEvent: public EventInterface{
private:
    Vector coords;
    PlayerManager& player_manager;
    char icon;
public:
    TeleportEvent(PlayerManager& player_manager, Vector coords);
    EventInterface* copy() override;
    void action() override;
    char getIcon() override;
    bool is_finite() override;
    ~TeleportEvent() override;
};


#endif //GAME_TELEPORTEVENT_H