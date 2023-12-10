#include "MazeGenerator.h"
#include <iostream>


MazeGenerator::MazeGenerator(unsigned int width_, unsigned int height_):
    width(width_ * 2 + 1), height(height_ * 2 + 1), maze_mask(new int[width * height]){
    for(int i = 0; i < height; i++){
        for(int j = 0; j < width; j++){
            if(i == 1 && j > 0 && j < width - 1) maze_mask[i * width + j] = 1;
            else if(i % 2 == 0) maze_mask[i * width + j] = 0;
            else if(j % 2 == 0) maze_mask[i * width + j] = 0;
            else if(i % 2 == 1 && j % 2 == 1) maze_mask[i * width + j] = 1;
            else maze_mask[i * width + j] = 0;
        }
    }
}


bool MazeGenerator::GetRandomDecision(){
    int x = rand();
    return x % 2;
}


Vector MazeGenerator::GetRandomCellCoordsFromSet(std::set<Vector>& cells){
    int index = rand() % cells.size();
    if(cells.size() == 1) index = 0;
    auto it = cells.begin();
    for(int k = 0; k < index; k++) it++;
    return *it;
}


void MazeGenerator::GenerateSidewinder(int seed){
    srand(seed);
    std::set<Vector> maze_cells;
    int cols = width - 1;
    int rows = height - 1;
    int current_row = 3;
    int current_col = 1;
    Vector current_cell;
    while(true){
        current_cell = Vector(current_col, current_row);
        maze_cells.insert(current_cell);
        if(GetRandomDecision() == true && (current_col + 2 < cols)){
            maze_mask[current_row * width + current_col + 1] = 1; // break right wall
            current_col += 2; // move right
        }
        else{
            Vector random_cell = GetRandomCellCoordsFromSet(maze_cells);
            maze_mask[(random_cell.y - 1) * width + random_cell.x] = 1; // break upper wall
            if(current_col + 2 < cols) current_col += 2;
            else if(current_row + 2 >= rows) break;
            else{
                current_row += 2;
                current_col = 1;
            }
            maze_cells.erase(maze_cells.begin(), maze_cells.end());
        }
    }
    for(int i = 0; i < height; i++){
        for(int j = 0; j < width; j++){
            std::cout << maze_mask[i * width + j] << " ";
        }
        std::cout << "\n";
    }
}


int* MazeGenerator::GetMazeMask(){
    return maze_mask;
}


MazeGenerator::~MazeGenerator(){
    delete[] maze_mask;
}