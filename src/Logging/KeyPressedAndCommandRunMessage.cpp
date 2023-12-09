#include "KeyPressedAndCommandRunMessage.h"



KeyPressedAndCommandRunMessage::KeyPressedAndCommandRunMessage(const char key, std::string command):
    key(key), command(command){

}


std::ostream& KeyPressedAndCommandRunMessage::to_stream(std::ostream& stream){
    stream << key << " " << command;
    return stream;
}


std::string KeyPressedAndCommandRunMessage::AcceptVisitor(MessageVisitor& visitor){
    return visitor.visit(*this);
}