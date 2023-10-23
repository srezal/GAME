#include "MazeLevel.h"


MazeLevel::MazeLevel(PlayerManager& player_manager, Vector maze_size, int coin_n, int trap_n, int teleport_n):
    player_manager(player_manager), maze_size(maze_size), coin_n(coin_n), trap_n(trap_n), teleport_n(teleport_n){
}


Field& MazeLevel::GetField(){
    Field* field = new Field(maze_size.x * 2 + 1, maze_size.y * 2 + 1, Vector(0, 0), Vector(maze_size.x * 2, maze_size.y * 2));
    field->GenerateMaze(time(NULL));
    for(int i = 0; i < coin_n; i++){   
        Vector coords = Vector(rand() % field->size().x, rand() % field->size().y);     
        while((field->getCell(coords).getCross_active() == false) || (field->getCell(coords).has_event() == true)){
            coords = Vector(rand() % field->size().x, rand() % field->size().y);
        }
        EventInterface* event = new PickUpCoinEvent(player_manager, 10);
        field->getCell(coords).setEventInterface(event);
    }
    for(int i = 0; i < trap_n; i++){   
        Vector coords = Vector(rand() % field->size().x, rand() % field->size().y);     
        while((field->getCell(coords).getCross_active() == false) || (field->getCell(coords).has_event() == true)){
            coords = Vector(rand() % field->size().x, rand() % field->size().y);
        }
        EventInterface* event = new TrapEvent(player_manager, 10);
        field->getCell(coords).setEventInterface(event);
    }
    for(int i = 0; i < teleport_n; i++){   
        Vector coords = Vector(rand() % field->size().x, rand() % field->size().y);     
        while((field->getCell(coords).getCross_active() == false) || (field->getCell(coords).has_event() == true)){
            coords = Vector(rand() % field->size().x, rand() % field->size().y);
        }
        Vector moved_coords = Vector(rand() % field->size().x, rand() % field->size().y);     
        while((field->getCell(moved_coords).getCross_active() == false) || (field->getCell(moved_coords).has_event() == true)){
            moved_coords = Vector(rand() % field->size().x, rand() % field->size().y);
        }
        EventInterface* event = new TeleportEvent(player_manager, moved_coords);
        field->getCell(coords).setEventInterface(event);
    }
    return *field;
}