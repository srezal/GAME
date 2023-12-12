#ifndef GAME_PLAYERWINMESSAGE_H
#define GAME_PLAYERWINMESSAGE_H

#include "MessageInterface.h"
#include <string>
#include <format>


class PlayerWinMessage: public MessageInterface{
private:
    const unsigned int playerHp;
public:
    PlayerWinMessage(const unsigned int);
    std::string getStringMessage() override;
};


#endif //GAME_PLAYERWINMESSAGE_H
