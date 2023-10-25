#include "FieldCreator.h"
#include "MazeGenerator.h"
#include <ctime>


Field& FieldCreator::create(LevelType level_type, Vector size){
    Field* field = new Field(size.x, size.y, Vector(1, 1), Vector(size.x - 1, size.y - 1));
    switch (level_type){
        case LevelType::MAZE:{
            MazeGenerator maze_generator = MazeGenerator(size.x, size.y);
            maze_generator.GenerateSidewinder(time(NULL));
            field->setCellsCrossActiveFromMask(maze_generator.GetMazeMask());
        }
        default:
            break;
    }
    return *field;
}