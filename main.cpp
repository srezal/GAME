#include <iostream>
#include "PlayerManager.h"
#include "Field.h"
#include "Printer.h"
#include "KeyListener.h"
#include "FieldCreator.h"
#include "LevelType.h"


int main() {
    Player player(100, 0);
    Field field;
    PlayerManager pm = PlayerManager(field, player, Vector(0, 0));
    field = FieldCreator().create(LevelType::MAZE, Vector(10, 10));
    Printer printer(field, pm, player);
    printer.clean();
    printer.print();
    KeyListener key_listener = KeyListener();
    while(true){
        char KEY = key_listener.listen();
        switch(KEY){
            case 'w':
                pm.changeCoord(Direction::TOP);
                break;
            case 's':
                pm.changeCoord(Direction::DOWN);
                break;
            case 'd':
                pm.changeCoord(Direction::RIGHT);
                break;
            case 'a':
                pm.changeCoord(Direction::LEFT);
                break;
            case '.':
                exit(0);
        };
        printer.clean();
        printer.print();
    }
    return 0;
}