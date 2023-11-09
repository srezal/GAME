#ifndef GAME_EVENTVISITORINTERFACE_H
#define GAME_EVENTVISITORINTERFACE_H


class TeleportEvent;
class TrapEvent;
class PickUpCoinEvent;
class PickUpKeyEvent;
class ShowExitEvent;
class BlindnessEvent;


class EventVisitorInterface{
public:
    virtual void visit(TeleportEvent) = 0;
    virtual void visit(TrapEvent) = 0;
    virtual void visit(PickUpCoinEvent) = 0;
    virtual void visit(PickUpKeyEvent) = 0;
    virtual void visit(ShowExitEvent) = 0;
    virtual void visit(BlindnessEvent) = 0;
};


#endif //GAME_EVENTVISITORINTERFACE_H