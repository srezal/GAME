#include "GameStartMessage.h"



GameStartMessage::GameStartMessage(const Vector field_size, const Vector start_position):
    field_size(field_size), start_position(start_position){
}


std::ostream& GameStartMessage::to_stream(std::ostream& stream){
    stream << field_size.x << "x" << field_size.y << " (" << start_position.x << " " << start_position.y << ")";
    return stream;
}


std::string GameStartMessage::AcceptVisitor(MessageVisitor& visitor){
    return visitor.visit(*this);
}