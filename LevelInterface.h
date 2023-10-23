#ifndef GAME_LEVELINTERFACE_H
#define GAME_LEVELINTERFACE_H


#include "Field.h"


class LevelInterface{
public:
    virtual Field& GetField() = 0;
    virtual ~LevelInterface(){};
};


#endif //GAME_LEVELINTERFACE_H