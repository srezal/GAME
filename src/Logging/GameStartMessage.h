#ifndef GAME_GAMESTARTMESSAGE_H
#define GAME_GAMESTARTMESSAGE_H

#include "MessageInterface.h"
#include "../Utils/Vector.h"
#include <string>


class GameStartMessage: public MessageInterface{
private:
    const Vector field_size;
    const Vector start_position;
public:
    GameStartMessage(const Vector, const Vector);
    std::string getStringMessage() override;
};


#endif //GAME_GAMESTARTMESSAGE_H
