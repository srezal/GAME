#ifndef GAME_EVENT_H
#define GAME_EVENT_H


class EventInterface{
public:
    virtual EventInterface* copy() = 0;
    virtual void action() = 0;
    virtual char getIcon() = 0;
    virtual bool is_finite() = 0;
    virtual ~EventInterface(){};
};


#endif //GAME_EVENT_H