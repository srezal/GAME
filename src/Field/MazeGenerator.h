#ifndef GAME_MAZEGENERATOR_H
#define GAME_MAZEGENERATOR_H


#include "../Utils/Vector.h"
#include <set>
#include <cstring>


#define DEFAULT_MAZE_WIDTH 10
#define DEFAULT_MAZE_HEIGHT 10


class MazeGenerator{
private:
    unsigned int width;
    unsigned int height;
    bool GetRandomDecision();
    Vector GetRandomCellCoordsFromSet(std::set<Vector>&);
    int* maze_mask;
public:
    MazeGenerator(unsigned int width = DEFAULT_MAZE_WIDTH, unsigned int height = DEFAULT_MAZE_HEIGHT);
    void GenerateSidewinder(int seed);
    int* GetMazeMask();
    ~MazeGenerator();
};


#endif //GAME_MAZEGENERATOR_H