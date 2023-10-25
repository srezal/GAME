#ifndef GAME_FIELDCREATOR_H
#define GAME_FIELDCREATOR_H


#include "Field.h"
#include "LevelType.h"


class FieldCreator{
public:
    Field& create(LevelType level_type, Vector);
};


#endif //GAME_FIELDCREATOR_H