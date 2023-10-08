#include <iostream>
#include "PlayerManager.h"
#include "Field.h"


int main() {
    Field field = Field(50, 50, Vector(0, 0), Vector(49, 49));
    Player player = Player(1000,0);
    PlayerManager player_manager(field, player, Vector(50, 50));
    std::cout << player_manager.getCoord().x << " " << player_manager.getCoord().y << "\n";
    player_manager.changeCoord(Direction::DOWN);
    player_manager.changeCoord(Direction::RIGHT);
    std::cout << player_manager.getCoord().x << " " << player_manager.getCoord().y << "\n";
    player_manager.changeCoord(Direction::TOP);
    player_manager.changeCoord(Direction::LEFT);
    std::cout << player_manager.getCoord().x << " " << player_manager.getCoord().y << "\n";
    field.getCell(Vector(47, 48)).setCross_active(false);
    player_manager.changeCoord(Direction::LEFT);
    std::cout << player_manager.getCoord().x << " " << player_manager.getCoord().y << "\n";
    field.getCell(Vector(47, 48)).setCross_active(true);
    player_manager.changeCoord(Direction::LEFT);
    std::cout << player_manager.getCoord().x << " " << player_manager.getCoord().y << "\n";
    // Field default_field = Field();
    // Field field = Field(MAX_BORDER, MAX_BORDER, Vector(0, 0), Vector(99, 99));
    // Field field_copy = field;
    // std::cout << field_copy.getCell(Vector(5, 5)).getCross_active() << "\n";
    // field_copy.getCell(Vector(5, 5)).setCross_active(0);
    // std::cout << field_copy.getCell(Vector(5, 5)).getCross_active() << " <-- field_copy\n";
    // std::cout << field.getCell(Vector(5, 5)).getCross_active() << " <-- field\n";
    // EventInterface* event = new EventInterface{EventInterface(777)};
    // field.getCell(Vector(5, 5)).setEventInterface(event);
    // std::cout << field.getCell(Vector(5, 5)).getEventInterface().get_data();
    return 0;
}