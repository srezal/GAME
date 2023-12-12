#include "KeyPressedAndCommandRunMessage.h"



KeyPressedAndCommandRunMessage::KeyPressedAndCommandRunMessage(const char key, std::string command):
    key(key), command(command){

}


std::string KeyPressedAndCommandRunMessage::getStringMessage(){
    return std::format("Key {} pressed and command {} run",
                    key,
                    command);
}