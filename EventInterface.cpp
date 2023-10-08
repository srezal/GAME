#include "EventInterface.h"
#include <utility>


EventInterface::EventInterface(int some_data): some_data(some_data){}


EventInterface::EventInterface(const EventInterface& other_event_interface){
    //конструктор копирования
    some_data = other_event_interface.some_data;
}


EventInterface& EventInterface::operator = (const EventInterface& other_event_interface){
    // переопределение оператора присваивания для конструктора копирования
    // EventInterface temp(other_event_interface);
    // std::swap(some_data, temp.some_data);
    // return *this;
}


int EventInterface::get_data() const{
    return some_data;
}