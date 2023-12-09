#include "FieldCreator.h"
#include "MazeGenerator.h"
#include "ArenaGenerator.h"
#include "../Events/PickUpKeyEvent.h"
#include "../Events/ShowExitEvent.h"
#include "../Events/BlindnessEvent.h"
#include "../Events/TeleportEvent.h"
#include "../Events/TrapEvent.h"
#include <ctime>


Vector FieldCreator::GenerateExitCoords(Field& field){
    int height = field.size().y;
    int width = field.size().x;
    int exit_orientation = rand() % 3;
    int x, y;
    switch(exit_orientation){
        case 0:
            x = width - 1;
            y = 1 + rand() % (height - 2);
            while(!field.getCell(Vector(x - 1, y)).isCross_active()) y = 1 + rand() % (height - 2);
            break;
        case 1:
            x = 1 + rand() % (width - 2);
            y = height - 1;
            while(!field.getCell(Vector(x, y - 1)).isCross_active()) x = 1 + rand() % (width - 2);
            break;
        case 2:
            x = 0;
            y = 1 + rand() % (height - 2);
            while(!field.getCell(Vector(x + 1, y)).isCross_active()) y = 1 + rand() % (height - 2);
            break;
    };
    return Vector(x, y);

}


FieldCell& FieldCreator::FindEmptyCell(Field& field){
    Vector cell_coords = Vector(rand() % field.size().x, rand() % field.size().y);
    while(!field.getCell(cell_coords).isCross_active() || field.getCell(cell_coords).has_event() || cell_coords == field.getStart_position()) cell_coords = Vector(rand() % field.size().x, rand() % field.size().y);
    return field.getCell(cell_coords);
}


Field& FieldCreator::create(LevelType level_type, Vector size){
    Field* field = nullptr;
    switch (level_type){
        case LevelType::MAZE:{
            field = new Field(size.x, size.y, Vector(0, 0), Vector(size.x - 1, size.y - 1), true);
            MazeGenerator maze_generator = MazeGenerator(size.x, size.y);
            maze_generator.GenerateSidewinder(time(NULL));
            field->setCellsCrossActiveFromMask(maze_generator.GetMazeMask());
            FindEmptyCell(*field).setEventInterface(new PickUpKeyEvent());
            field->setFinish_position(GenerateExitCoords(*field));
            FindEmptyCell(*field).setEventInterface(new ShowExitEvent());
            FindEmptyCell(*field).setEventInterface(new BlindnessEvent());
            FindEmptyCell(*field).setEventInterface(new TeleportEvent());
            for(int i = 0; i < 5; i++) FindEmptyCell(*field).setEventInterface(new TrapEvent(10));
            break;
        }
        case LevelType::ARENA:{
            field = new Field(size.x, size.y, Vector(0, 0), Vector(size.x - 1, size.y - 1), false);
            ArenaGenerator arena_generator = ArenaGenerator(size.x, size.y);
            arena_generator.GenerateArena(time(NULL));
            field->setCellsCrossActiveFromMask(arena_generator.GetArenaMask());
            break;
        }
        default:
            break;
    }
    return *field;
}