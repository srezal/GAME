#include <iostream>
#include "PlayerManager.h"

int main() {
    Player pp = Player(100,0);
    Vector a(1, 1, {0, 100}, {0, 100});
    printf("%d %d\n", a.x, a.y);
    PlayerManager player_manager(pp, Vector(-90, 20,{0, 100},{0, 100}));
    printf("%d %d %d %d\n", pp.getHealth(), pp.getScore(), player_manager.getCoord().x, player_manager.getCoord().y);
    player_manager.addHealth(-40);
    player_manager.addHealth(20);
    player_manager.addScore(1200);
    player_manager.changeCoord(Direction::TOP);
    printf("%d %d %d %d\n", pp.getHealth(), pp.getScore(), player_manager.getCoord().x, player_manager.getCoord().y);
    return 0;
}