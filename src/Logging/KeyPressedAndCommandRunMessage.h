#ifndef GAME_KEYPRESSEDANDCOMMANDRUNMESSAGE_H
#define GAME_KEYPRESSEDANDCOMMANDRUNMESSAGE_H

#include "MessageInterface.h"
#include "../Utils/Vector.h"
#include <string>
#include "../Game/CommandsEnum.h"
#include <map>
#include <string>
#include <format>


class KeyPressedAndCommandRunMessage: public MessageInterface{
private:
    char key;
    std::string command;
public:
    KeyPressedAndCommandRunMessage(const char, std::string);
    std::string getStringMessage() override;
};


#endif //GAME_KEYPRESSEDANDCOMMANDRUNMESSAGE_H
