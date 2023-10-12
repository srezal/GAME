#include <iostream>
#include "PlayerManager.h"
#include "Field.h"


int main() {
    std::cout << "Инициализация поля через конструктор без аргументов: \n";
    Field default_field = Field();
    std::cout << "(default_field): size = " << default_field.size().x << "x" << default_field.size().y << " random cell cross_active = " << default_field.getCell(Vector(24, 24)).getCross_active() << "\n";
    
    std::cout << "\nИнициализация поля размером 37x45: \n";
    Field field = Field(37, 45, Vector(0, 0), Vector(23, 35));
    std::cout << "(field): size = " << field.size().x << "x" << field.size().y << " start_position = (" << field.getStart_position().x << "," << field.getStart_position().y << ")";
    std::cout << " finish_position = (" << field.getFinish_position().x << "," << field.getFinish_position().y << ")\n";

    std::cout << "\nИнициализация нового поля через конструктор копирования:\n";
    Field field_copy(field);
    std::cout << "(field_copy): size = " << field_copy.size().x << "x" << field_copy.size().y << " start_position = (" << field_copy.getStart_position().x << "," << field_copy.getStart_position().y << ")";
    std::cout << " finish_position = (" << field_copy.getFinish_position().x << "," << field_copy.getFinish_position().y << ")\n";

    std::cout << "\nИзменение данных в field_copy и проверка, что данные в field не изменяются:\n";
    field_copy.getCell(Vector(11, 12)).setCross_active(0);
    std::cout << "(field_copy -> cell 11x12): cross_active = " << field_copy.getCell(Vector(11, 12)).getCross_active() << "\n";
    std::cout << "(field -> cell 11x12): cross_active = " << field.getCell(Vector(11, 12)).getCross_active() << "\n";
    field.getCell(Vector(11, 12)).setEventInterface(nullptr);
    std::cout << "(field): cell 11x12 has_event = " << field.getCell(Vector(11, 12)).has_event() << "\n";


    std::cout << "\nИнициализация нового поля через конструктор перемещения:\n";
    Field moved_field(std::move(default_field));
    std::cout << "(moved_field): size = " << moved_field.size().x << "x" << moved_field.size().y << " random cell cross_active = " << moved_field.getCell(Vector(24, 24)).getCross_active() << "\n";


    Player player = Player(100, 100);
    PlayerManager player_manager = PlayerManager(moved_field, player, Vector(100, 100));
    player_manager.changeCoord(Direction::TOP);
    player_manager.changeCoord(Direction::LEFT);
    std::cout << "(player): coordinates = (" << player_manager.getCoord().x << ", " << player_manager.getCoord().y << ")\n";
    moved_field.getCell(Vector(22, 23)).setCross_active(0);
    player_manager.changeCoord(Direction::LEFT);
    player_manager.changeCoord(Direction::LEFT);
    player_manager.changeCoord(Direction::LEFT);
    player_manager.changeCoord(Direction::LEFT);
    std::cout << "(player): coordinates = (" << player_manager.getCoord().x << ", " << player_manager.getCoord().y << ")\n";
    moved_field.getCell(Vector(22, 23)).setCross_active(1);
    player_manager.changeCoord(Direction::LEFT);
    player_manager.changeCoord(Direction::LEFT);
    player_manager.changeCoord(Direction::LEFT);
    player_manager.changeCoord(Direction::LEFT);
    std::cout << "(player): coordinates = (" << player_manager.getCoord().x << ", " << player_manager.getCoord().y << ")\n";
    return 0;
}