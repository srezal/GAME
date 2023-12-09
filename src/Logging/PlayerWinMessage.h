#ifndef GAME_PLAYERWINMESSAGE_H
#define GAME_PLAYERWINMESSAGE_H

#include "MessageInterface.h"
#include "MessageVisitor.h"
#include <string>


class PlayerWinMessage: public MessageInterface{
private:
    const unsigned int playerHp;
public:
    PlayerWinMessage(const unsigned int);
    std::ostream& to_stream(std::ostream&) override;
    std::string AcceptVisitor(MessageVisitor&) override;
};


#endif //GAME_PLAYERWINMESSAGE_H
