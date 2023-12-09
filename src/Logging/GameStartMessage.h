#ifndef GAME_GAMESTARTMESSAGE_H
#define GAME_GAMESTARTMESSAGE_H

#include "MessageInterface.h"
#include "MessageVisitor.h"
#include "../Utils/Vector.h"
#include <string>


class GameStartMessage: public MessageInterface{
private:
    const Vector field_size;
    const Vector start_position;
public:
    GameStartMessage(const Vector, const Vector);
    std::ostream& to_stream(std::ostream&) override;
    std::string AcceptVisitor(MessageVisitor&) override;
};


#endif //GAME_GAMESTARTMESSAGE_H
