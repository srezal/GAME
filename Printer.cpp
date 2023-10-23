#include <iostream>
#include "Printer.h"


Printer::Printer(Field& field, PlayerManager& player_manager, Player& player): field(field), player_manager(player_manager), player(player){};


void Printer::print(){
    std::cout << "Health: " << player.getHealth() << "\n";
    std::cout << "Score: " << player.getScore() << "\n";
    for(int i = 0; i < field.size().y; i++){
        for(int j = 0; j < field.size().x; j++){
            Vector current_cell_coords = Vector(j, i);
            if(player_manager.getCoord() == current_cell_coords) std::cout << "ъ ";
            else if(field.getCell(current_cell_coords).getCross_active() == 0){
                std::cout << "* ";
            }
            else if(field.getCell(current_cell_coords).has_event() == true){
                std::cout << field.getCell(current_cell_coords).getEventInterface().getIcon() << " ";
            }
            else std::cout << "  ";
        }
        std::cout << "\n";
    }
    std::cout << std::endl;
}


void Printer::clean(){
    std::cout << "\033[2J\033[1;1H";
}