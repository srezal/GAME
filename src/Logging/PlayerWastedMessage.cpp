#include "PlayerWastedMessage.h"



PlayerWastedMessage::PlayerWastedMessage(const Vector last_cell_position): last_cell_position(last_cell_position){
}


std::string PlayerWastedMessage::getStringMessage(){
    return std::format("Player wasted on cell ({}, {})",
                    last_cell_position.x,
                    last_cell_position.y);
}