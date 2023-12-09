#include "ArenaGenerator.h"

#include <iostream>


ArenaGenerator::ArenaGenerator(unsigned int width_, unsigned int height_):
    width(width_ * 2 + 1), height(height_ * 2 + 1), arena_mask(new int[width * height]){
    for(int i = 0; i < height; i++){
        for(int j = 0; j < width; j++){
            if(i > 0 && i < height - 1 && j > 0 && j < width - 1) arena_mask[width * i + j] = 1;
            else arena_mask[width * i + j] = 0;
        }
    }
}


bool ArenaGenerator::GetRandomDecision(){
    int x = rand();
    return x % 2;
}


void ArenaGenerator::GenerateArena(int seed){
    srand(seed);
}


int* ArenaGenerator::GetArenaMask(){
    return arena_mask;
}


ArenaGenerator::~ArenaGenerator(){
    delete[] arena_mask;
}