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


void Printer::printKey(){
    std::cout << "k ";
}


void Printer::printPlayerStats(){
    std::cout << "Health: " << player.getHealth() << "\n";
    std::cout << "Score: " << player.getScore() << "\n";
    std::cout << "Key: " << player.Has_key() << "\n";
    std::cout << "Vision distance: " << player.getVision_distane() << "\n";
}


void Printer::printEmptyCell(){
    std::cout << "  ";
}


void Printer::printDarkness(){
    std::cout << "= ";
}


void Printer::printExit(){
    std::cout << "E ";
}

void Printer::printEye(){
    std::cout << "0 ";
}

void Printer::printBlindnessPill(){
    std::cout << "p ";
}

void Printer::print(){
    Printer::printPlayerStats();
    PrintToConsoleVisitor visitor = PrintToConsoleVisitor(*this);
    for(int i = 0; i < field.size().y; i++){
        for(int j = 0; j < field.size().x; j++){
            Vector current_cell_coords = Vector(j, i);
            if(player_manager.getCoord() == current_cell_coords) Printer::printPlayer();
            else if(!field.getCell(current_cell_coords).isVisible()){
                if(current_cell_coords == field.getFinish_position() && player.isKnow_where_is_exit()){
                    Printer::printExit();
                }
                else Printer::printDarkness();
            }
            else if(current_cell_coords == field.getFinish_position()) Printer::printExit();
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