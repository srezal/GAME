#include "KeyPressedMessage.h"



KeyPressedMessage::KeyPressedMessage(const char key):
    key(key){
}


std::ostream& KeyPressedMessage::to_stream(std::ostream& stream){
    stream << key;
    return stream;
}


std::string KeyPressedMessage::AcceptVisitor(MessageVisitor& visitor){
    return visitor.visit(*this);
}