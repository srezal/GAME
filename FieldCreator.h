#ifndef GAME_FIELDCREATOR_H
#define GAME_FIELDCREATOR_H


#include "Field.h"
#include "LevelInterface.h"


class FieldCreator{
public:
    FieldCreator();
    Field& create(LevelInterface& level);
};


#endif //GAME_FIELDCREATOR_H