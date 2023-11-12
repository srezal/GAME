#ifndef GAME_PRINTER_H
#define GAME_PRINTER_H


#include "Field.h"
#include "PlayerManager.h"
#include "Player.h"


class Printer{
private:
    Field& field;
    PlayerManager& player_manager;
    Player& player;
public:
    Printer(Field& field, PlayerManager& player_manager, Player& player);
    void printMsg(std::string);
    void printTeleport();
    void printTrap();
    void printCoin();
    void printWall();
    void printPlayer();
    void printPlayerStats();
    void printEmptyCell();
    void printDarkness();
    void printKey();
    void printExit();
    void printEye();
    void printBlindnessPill();
    void print();
    void clean();
};


#endif //GAME_PRINTER_H