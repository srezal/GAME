#include "FieldCell.h"
#include <iostream>
#include <time.h>


FieldCell::FieldCell(bool cross_active, bool visible, EventInterface* event): cross_active(cross_active), visible(visible), event(event){}


FieldCell::FieldCell(const FieldCell& other_field_cell): cross_active(1), event(nullptr){
    cross_active = other_field_cell.cross_active;
    visible = other_field_cell.visible;
    if(other_field_cell.has_event() == true){
        event = other_field_cell.getEventInterface().copy();
    }
}


FieldCell& FieldCell::operator=(const FieldCell& other_field_cell){
    FieldCell temp(other_field_cell);
    std::swap(cross_active,  temp.cross_active);
    std::swap(visible, temp.visible);
    std::swap(event, temp.event);
    return *this;
}


FieldCell::FieldCell(FieldCell&& other_field_cell){
    std::swap(cross_active, other_field_cell.cross_active);
    std::swap(visible, other_field_cell.visible);
    std::swap(event, other_field_cell.event);
}


FieldCell& FieldCell::operator=(FieldCell&& other_field_cell){
    if(this != &other_field_cell){
        std::swap(cross_active, other_field_cell.cross_active);
        std::swap(visible, other_field_cell.visible);
        std::swap(event, other_field_cell.event);
    }
    return *this;
}


void FieldCell::setCross_active(bool value){
    cross_active = value;
}


bool FieldCell::isCross_active() const{
    return cross_active;
}


bool FieldCell::isVisible() const{
    return visible;
}


void FieldCell::setVisible(bool value){
    visible = value;
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