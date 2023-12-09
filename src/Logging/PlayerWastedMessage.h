#ifndef GAME_PLAYERWASTEDMESSAGE_H
#define GAME_PLAYERWASTEDMESSAGE_H

#include "MessageInterface.h"
#include "MessageVisitor.h"
#include "../Utils/Vector.h"


class PlayerWastedMessage: public MessageInterface{
private:
    const Vector last_cell_position;
public:
    PlayerWastedMessage(const Vector);
    std::ostream& to_stream(std::ostream&) override;
    std::string AcceptVisitor(MessageVisitor&) override;
};


#endif //GAME_PLAYERWASTEDMESSAGE_H
