#ifndef GAME_MAZELEVEL_H
#define GAME_MAZELEVEL_H


#include "LevelInterface.h"
#include "Player.h"
#include "PlayerManager.h"
#include "Vector.h"
#include "TrapEvent.h"
#include "TeleportEvent.h"
#include "PickUpCoinEvent.h"
#include <time.h>



class MazeLevel: public LevelInterface{
private:
    PlayerManager& player_manager;
    Vector maze_size;
    int coin_n;
    int trap_n;
    int teleport_n;
public:
    MazeLevel(PlayerManager& player_manager, Vector maze_size, int coin_n, int trap_n, int teleport_n);
    Field& GetField() override;
};


#endif //GAME_MAZELEVEL_H