#include "FieldCell.h"


FieldCell::FieldCell(): cross_active(true), event(nullptr){}


FieldCell::FieldCell(bool cross_active = true, EventInterface* event = nullptr): cross_active(cross_active), event(event){}


void FieldCell::setCross_active(bool value){
    cross_active = value;
}


bool FieldCell::getCross_active() const{
    return cross_active;
}


void FieldCell::setEventInterface(EventInterface* event){
    if(this->event != nullptr) delete this->event;
    this->event = event;
}


EventInterface& FieldCell::getEventInterface() const{
    return *event; // when calling must be checked if has event
}


bool FieldCell::has_event() const{
    return (event != nullptr);
}


FieldCell::~FieldCell(){
    if(event != nullptr) delete event;
}