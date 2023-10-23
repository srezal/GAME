#ifndef GAME_TRAPEVENT_H
#define GAME_TRAPEVENT_H


#include "EventInterface.h"
#include "PlayerManager.h"


class TrapEvent: public EventInterface{
private:
    unsigned int damage_size;
    PlayerManager& player_manager;
    char icon;
public:
    TrapEvent(PlayerManager& player_manager, unsigned int damage_size);
    EventInterface* copy() override;
    void action() override;
    char getIcon() override;
    bool is_finite() override;
    ~TrapEvent() override;
};


#endif //GAME_TRAPEVENT_H