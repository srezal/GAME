#ifndef GAME_PLAYERMANAGER_H
#define GAME_PLAYERMANAGER_H


#include <memory>
#include "Vector.h"
#include "Player.h"
#include "Direction.h"
#include "Field.h"
#include "LightController.h"
#include "GameStatus.h"


class PlayerManager {
private:
    Player& player;
    Field& field;
    Vector coord;
    LightController light_controller;
    bool win;
public:
    PlayerManager(Field& field, Player& player, const Vector& coord);
    void addHealth(int addition);
    void addScore(unsigned int addition);
    void tpPlayerToStartPosition();
    void changeCoord(Direction dir);
    void setCoord(const Vector& newCoord);
    void setHas_key(bool has_key);
    void setKnow_where_is_exit(bool value);
    void DecreaseVision(unsigned int value);
    bool isWin() const;
    unsigned int getHealth() const;
    const Vector& getCoord();
};


#endif //GAME_PLAYERMANAGER_H
