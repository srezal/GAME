#include "PlayerWastedMessage.h"



PlayerWastedMessage::PlayerWastedMessage(const Vector last_cell_position): last_cell_position(last_cell_position){
}


std::ostream& PlayerWastedMessage::to_stream(std::ostream& stream){
    stream << "(" << last_cell_position.x << " " << last_cell_position.y << ")";
    return stream;
}


std::string PlayerWastedMessage::AcceptVisitor(MessageVisitor& visitor){
    return visitor.visit(*this);
}