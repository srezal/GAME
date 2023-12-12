#include "KeyPressedMessage.h"



KeyPressedMessage::KeyPressedMessage(const char key):
    key(key){
}


std::string KeyPressedMessage::getStringMessage(){
    return std::format("Key {} pressed.", key);
}