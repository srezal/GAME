#ifndef GAME_EVENTVISITORINTERFACE_H
#define GAME_EVENTVISITORINTERFACE_H


class TeleportEvent;
class TrapEvent;
class PickUpCoinEvent;


class EventVisitorInterface{
public:
    virtual void visit(TeleportEvent) = 0;
    virtual void visit(TrapEvent) = 0;
    virtual void visit(PickUpCoinEvent) = 0;
};


#endif //GAME_EVENTVISITORINTERFACE_H