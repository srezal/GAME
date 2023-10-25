#include <iostream>
#include "Printer.h"
#include "PrintToConsoleVisitor.h"


Printer::Printer(Field& field, PlayerManager& player_manager, Player& player): field(field), player_manager(player_manager), player(player){};


void Printer::printTeleport(){
    std::cout << "? ";
}


void Printer::printTrap(){
    std::cout << "x ";
}


void Printer::printCoin(){
    std::cout << "$ ";
}


void Printer::printWall(){
    std::cout << "* ";
}


void Printer::printPlayer(){
    std::cout << "ъ ";
}


void Printer::printPlayerStats(){
    std::cout << "Health: " << player.getHealth() << "\n";
    std::cout << "Score: " << player.getScore() << "\n";
}


void Printer::printEmptyCell(){
    std::cout << "  ";
}


void Printer::print(){
    Printer::printPlayerStats();
    PrintToConsoleVisitor visitor = PrintToConsoleVisitor(*this);
    for(int i = 0; i < field.size().y; i++){
        for(int j = 0; j < field.size().x; j++){
            Vector current_cell_coords = Vector(j, i);
            if(player_manager.getCoord() == current_cell_coords) Printer::printPlayer();
            else if(!field.getCell(current_cell_coords).isCross_active()){
                Printer::printWall();
            }
            else if(field.getCell(current_cell_coords).has_event()){
                field.getCell(current_cell_coords).getEventInterface().AcceptVisitor(visitor); //genius?
            }
            else Printer::printEmptyCell();
        }
        std::cout << "\n";
    }
    std::cout << std::endl;
}


void Printer::clean(){
    std::cout << "\033[2J\033[1;1H";
}