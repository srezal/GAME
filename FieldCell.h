#ifndef GAME_FIELDCELL_H
#define GAME_FIELDCELL_H


#include "EventInterface.h"
#include <algorithm>


class FieldCell{
private:
    bool cross_active;
    EventInterface* event;
public:
    FieldCell();
    FieldCell(bool cross_active, EventInterface* event);
    FieldCell(const FieldCell& other_field_cell);
    FieldCell(FieldCell&& other_field_cell);
    FieldCell& operator = (const FieldCell& other_field_cell);
    FieldCell& operator = (FieldCell&& other_field_cell);
    void setCross_active(bool value);
    bool getCross_active() const;
    void setEventInterface(EventInterface* event);
    EventInterface& getEventInterface() const;
    bool has_event() const;
    ~FieldCell();
};


#endif //GAME_FIELDCELL_H
