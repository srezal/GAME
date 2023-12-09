#ifndef GAME_KEYPRESSEDMESSAGE_H
#define GAME_KEYPRESSEDMESSAGE_H

#include "MessageInterface.h"
#include "MessageVisitor.h"
#include "../Utils/Vector.h"
#include <string>


class KeyPressedMessage: public MessageInterface{
private:
    char key;
public:
    KeyPressedMessage(const char);
    std::ostream& to_stream(std::ostream&) override;
    std::string AcceptVisitor(MessageVisitor&) override;
};


#endif //GAME_KEYPRESSEDMESSAGE_H
