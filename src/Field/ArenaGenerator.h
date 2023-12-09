#ifndef GAME_ARENAGENERATOR_H
#define GAME_ARENAGENERATOR_H

#include "../Utils/Vector.h"


#define DEFAULT_ARENA_WIDTH 10
#define DEFAULT_ARENA_HEIGHT 10



class ArenaGenerator{
private:
    unsigned int width;
    unsigned int height;
    bool GetRandomDecision();
    int* arena_mask;
public:
    ArenaGenerator(unsigned int width = DEFAULT_ARENA_WIDTH, unsigned int height = DEFAULT_ARENA_HEIGHT);
    void GenerateArena(int seed);
    int* GetArenaMask();
    ~ArenaGenerator();
};

#endif //GAME_ARENAGENERATOR_H