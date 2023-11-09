#ifndef GAME_FIELDCELL_H
#define GAME_FIELDCELL_H


#include "Events/EventInterface.h"
#include <algorithm>


class FieldCell{
private:
    bool cross_active;
    bool visible;
    EventInterface* event;
public:
    FieldCell(bool cross_active=true, bool visible=false, EventInterface* event=nullptr);
    FieldCell(const FieldCell& other_field_cell);
    FieldCell(FieldCell&& other_field_cell);
    FieldCell& operator = (const FieldCell& other_field_cell);
    FieldCell& operator = (FieldCell&& other_field_cell);
    void setCross_active(bool value);
    bool isCross_active() const;
    bool isVisible() const;
    void setVisible(bool value);
    void setEventInterface(EventInterface* event);
    EventInterface& getEventInterface() const;
    bool has_event() const;
    ~FieldCell();
};


#endif //GAME_FIELDCELL_H
