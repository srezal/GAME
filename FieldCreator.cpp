#include "FieldCreator.h"


FieldCreator::FieldCreator(){}


Field& FieldCreator::create(LevelInterface& level){
    return level.GetField();
}