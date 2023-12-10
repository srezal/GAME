#include <iostream>
#include "Printer.h"
#include "../Events/PrintToConsoleVisitor.h"


Printer::Printer(Field& field, PlayerManager& player_manager, Player& player): field(field), player_manager(player_manager), player(player){
    std::setlocale(LC_ALL,"en_US.UTF-8");
};


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
    std::cout << "■ ";
}


void Printer::printPlayer(){
    std::cout << "🌶 ";
}


void Printer::printKey(){
    std::cout << "k ";
}


void Printer::printEmptyCell(){
    std::cout << "  ";
}


void Printer::printDarkness(){
    std::cout << "░ ";
}


void Printer::printExit(){
    std::cout << "⚐ ";
}

void Printer::printEye(){
    std::cout << "⦾ ";
}

void Printer::printBlindnessPill(){
    std::cout << "p ";
}


void Printer::printPlayerStats(){
    std::cout << "Health: " << player.getHealth() << "\n";
    //std::cout << "Score: " << player.getScore() << "\n";
    std::cout << "Key: " << player.Has_key() << "\n";
    std::cout << "Vision distance: " << player.getVision_distane() << "\n";
}


void Printer::print(){
    clean();
    printPlayerStats();
    PrintToConsoleVisitor visitor = PrintToConsoleVisitor(*this);
    for(int i = 0; i < field.size().y; i++){
        for(int j = 0; j < field.size().x; j++){
            Vector current_cell_coords = Vector(j, i);
            if(player_manager.getCoord() == current_cell_coords) printPlayer();
            else if(!field.getCell(current_cell_coords).isVisible()){
                if(current_cell_coords == field.getFinish_position() && player.isKnow_where_is_exit()){
                    printExit();
                }
                else printDarkness();
            }
            else if(current_cell_coords == field.getFinish_position()) printExit();
            else if(!field.getCell(current_cell_coords).isCross_active()){
                printWall();
            }
            else if(field.getCell(current_cell_coords).has_event()){
                field.getCell(current_cell_coords).getEventInterface().AcceptVisitor(visitor); //genius?
            }
            else printEmptyCell();
        }
        std::cout << "\n";
    }
    std::cout << std::endl;
}


void Printer::clean(){
    system("clear");
}