#ifndef GAME_FIELDCELL_H
#define GAME_FIELDCELL_H


#include "EventInterface.h"


class FieldCell{
private:
    bool cross_active;
    EventInterface* event;
public:
    FieldCell();
    FieldCell(bool cross_active, EventInterface* event);
    void setCross_active(bool value);
    bool getCross_active() const;
    void setEventInterface(EventInterface* event);
    EventInterface& getEventInterface() const;
    bool has_event() const;
    ~FieldCell();
};


#endif //GAME_FIELDCELL_H
