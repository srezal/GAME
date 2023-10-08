#include "FieldCell.h"

#include <iostream>


FieldCell::FieldCell(): cross_active(true), event(nullptr){}


FieldCell::FieldCell(bool cross_active = true, EventInterface* event = nullptr): cross_active(cross_active), event(event){}


FieldCell::FieldCell(const FieldCell& other_field_cell): cross_active(1), event(nullptr){
    cross_active = other_field_cell.cross_active;
    if(other_field_cell.has_event() == true){
        event = new EventInterface;
        *event = other_field_cell.getEventInterface();
        std::cout << event << "\n";
    }
}


FieldCell& FieldCell::operator=(const FieldCell& other_field_cell){
    FieldCell temp(other_field_cell);
    std::swap(cross_active,  temp.cross_active);
    std::swap(event, temp.event);
    return *this;
}


FieldCell::FieldCell(FieldCell&& other_field_cell){
    std::swap(cross_active, other_field_cell.cross_active);
    std::swap(event, other_field_cell.event);
}


FieldCell& FieldCell::operator=(FieldCell&& other_field_cell){
    if(this != &other_field_cell){
        std::swap(cross_active, other_field_cell.cross_active);
        std::swap(event, other_field_cell.event);
    }
    return *this;
}


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