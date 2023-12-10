#ifndef GAME_LIGHTCONTROLLER_H
#define GAME_LIGHTCONTROLLER_H


#include "../Utils/Vector.h"
#include "../Field/Field.h"
#include "../Utils/Direction.h"


class LightController{
public:
    void fillLight(Field& field, Vector player_coords, int distance);
    void setLight(Field& field, Vector player_coords, int distance);
    void setPitchDarkness(Field& field);
    void removeLight(Field& field, Vector player_coords, int distance);
};


#endif //GAME_LIGHTCONTROLLER_H