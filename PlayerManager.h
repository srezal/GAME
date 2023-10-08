#ifndef GAME_PLAYERMANAGER_H
#define GAME_PLAYERMANAGER_H


#define MIN_BORDER 0

#include <memory>
#include "Vector.h"
#include "Player.h"
#include "Direction.h"
#include "Field.h"


class PlayerManager {
private:
    Player& player;
    Field& field;
    Vector coord;
public:
    PlayerManager(Field& field, Player& player, const Vector& coord);
    void addHealth(int addition);
    void addScore(unsigned int addition);
    void changeCoord(Direction dir);
    void setCoord(const Vector& newCoord);
    const Vector& getCoord();
};


#endif //GAME_PLAYERMANAGER_H
