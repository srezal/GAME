#ifndef GAME_KEYPRESSEDANDCOMMANDRUNMESSAGE_H
#define GAME_KEYPRESSEDANDCOMMANDRUNMESSAGE_H

#include "MessageInterface.h"
#include "MessageVisitor.h"
#include "../Utils/Vector.h"
#include <string>
#include "../Game/CommandsEnum.h"
#include <map>
#include <string>


class KeyPressedAndCommandRunMessage: public MessageInterface{
private:
    char key;
    std::string command;
public:
    KeyPressedAndCommandRunMessage(const char, std::string);
    std::ostream& to_stream(std::ostream&) override;
    std::string AcceptVisitor(MessageVisitor&) override;
};


#endif //GAME_KEYPRESSEDANDCOMMANDRUNMESSAGE_H
