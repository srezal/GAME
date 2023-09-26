#include <iostream>
#include "PlayerManager.h"

int main() {
    Player player = Player(1000,0);
    PlayerManager player_manager(player, Vector(50, 50));
    printf("%d %d %d %d\n", player.getHealth(), player.getScore(), player_manager.getCoord().x, player_manager.getCoord().y);
    player_manager.addHealth(-90);
    player_manager.addHealth(11);
    player_manager.addScore(1314);
    player_manager.changeCoord(Direction::TOP);
    printf("%d %d %d %d\n", player.getHealth(), player.getScore(), player_manager.getCoord().x, player_manager.getCoord().y);
    return 0;
}