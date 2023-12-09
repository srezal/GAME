#include "Game/Game.h"
#include "Config/Config.h"



int main() {
    Config conf = Config();
    Game game = Game(conf);
    game.StartGame();
    return 0;
}