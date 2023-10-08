#ifndef GAME_PLAYERMANAGER_H
#define GAME_PLAYERMANAGER_H


#define MIN_BORDER 0
#define MAX_BORDER 100

#include <memory>
#include "Vector.h"
#include "Player.h"
#include "Direction.h"


class PlayerManager {
private:
    Player& player;
    Vector coord;
public:
    PlayerManager(Player& player, const Vector& coord);
    void addHealth(int addition);
    void addScore(unsigned int addition);
    void changeCoord(Direction dir);
    void setCoord(const Vector& newCoord);
    const Vector& getCoord();
};


#endif //GAME_PLAYERMANAGER_H
