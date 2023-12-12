#include <format>
#include "GameStartMessage.h"



GameStartMessage::GameStartMessage(const Vector field_size, const Vector start_position):
    field_size(field_size), start_position(start_position){
}


std::string GameStartMessage::getStringMessage(){
    return std::format("Start a new game. Field size is {}x{} and players start position is ({}, {})",
                        field_size.x,
                        field_size.y, 
                        start_position.x, 
                        start_position.y);
}