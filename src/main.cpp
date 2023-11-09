#include <iostream>
#include "PlayerManager.h"
#include "Field.h"
#include "Printer.h"
#include "KeyListener.h"
#include "FieldCreator.h"
#include "LevelType.h"
#include "LightController.h"


int main() {
    Player player(100, 0, 4);
    Field field = FieldCreator().create(LevelType::MAZE, Vector(15, 15));
    PlayerManager pm = PlayerManager(field, player, Vector(0, 0));
    Printer printer(field, pm, player);
    printer.clean();
    printer.print();
    KeyListener key_listener = KeyListener();
    while(true){
        char KEY = key_listener.listen();
        Direction dir;
        switch(KEY){
            case 'w':
                dir = Direction::TOP;
                break;
            case 's':
                dir = Direction::DOWN;
                break;
            case 'd':
                dir = Direction::RIGHT;
                break;
            case 'a':
                dir = Direction::LEFT;
                break;
            case '.':
                exit(0);
        };
        pm.changeCoord(dir);
        printer.clean();
        printer.print();
    }
    return 0;
}