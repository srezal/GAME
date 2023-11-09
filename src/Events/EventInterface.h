#ifndef GAME_EVENTINTERFACE_H
#define GAME_EVENTINTERFACE_H


class EventVisitorInterface;
class PlayerManager;


class EventInterface{
public:
    virtual EventInterface* copy() = 0;
    virtual void action(PlayerManager&) = 0;
    virtual void AcceptVisitor(EventVisitorInterface&) = 0;
    virtual ~EventInterface(){};
};


#endif //GAME_EVENTINTERFACE_H