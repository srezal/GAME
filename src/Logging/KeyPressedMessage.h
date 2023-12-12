#ifndef GAME_KEYPRESSEDMESSAGE_H
#define GAME_KEYPRESSEDMESSAGE_H

#include "MessageInterface.h"
#include "../Utils/Vector.h"
#include <string>
#include <format>


class KeyPressedMessage: public MessageInterface{
private:
    char key;
public:
    KeyPressedMessage(const char);
    std::string getStringMessage() override;
};


#endif //GAME_KEYPRESSEDMESSAGE_H
