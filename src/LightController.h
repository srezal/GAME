#ifndef GAME_LIGHTCONTROLLER_H
#define GAME_LIGHTCONTROLLER_H


#include "Vector.h"
#include "Field.h"
#include "Direction.h"


class LightController{
public:
    void setLight(Field& field, Vector player_coords, int distance);
    void removeLight(Field& field, Vector player_coords, int distance);
};


#endif //GAME_LIGHTCONTROLLER_H