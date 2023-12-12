#ifndef GAME_PLAYERWASTEDMESSAGE_H
#define GAME_PLAYERWASTEDMESSAGE_H

#include "MessageInterface.h"
#include "../Utils/Vector.h"
#include <string>
#include <format>


class PlayerWastedMessage: public MessageInterface{
private:
    const Vector last_cell_position;
public:
    PlayerWastedMessage(const Vector);
    std::string getStringMessage() override;
};


#endif //GAME_PLAYERWASTEDMESSAGE_H
