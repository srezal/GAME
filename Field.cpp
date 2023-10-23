#include "Field.h"
#include <iostream>
#include <cstring>


Field::Field(){
    rows = DEFAULT_SIZE;
    cols = DEFAULT_SIZE;
    start_position = Vector(1, 1);
    finish_position = Vector(DEFAULT_SIZE - 2, DEFAULT_SIZE - 2);
    cells = new FieldCell[rows * cols];
}


Field::Field(unsigned int height, unsigned int width, const Vector& start_position, const Vector& finish_position){
    this->rows = std::clamp((int)(height * 2 + 1), MIN_BORDER, MAX_BORDER);
    this->cols = std::clamp((int)(width * 2 + 1), MIN_BORDER, MAX_BORDER);
    this->start_position = Vector(start_position.x * 2 + 1, start_position.y * 2 + 1, {MIN_BORDER, this->cols - 1}, {MIN_BORDER, this->rows - 1});
    this->finish_position = Vector(finish_position.x * 2 + 1, finish_position.y * 2 + 1, {MIN_BORDER, this->cols - 1}, {MIN_BORDER, this->rows - 1});
    cells = new FieldCell[this->rows * this->cols];
}


Field::Field(const Field& other_field){
    rows = other_field.rows;
    cols = other_field.cols;
    start_position = other_field.start_position;
    finish_position = other_field.finish_position;
    cells = new FieldCell[rows * cols];
    std::copy(other_field.cells, other_field.cells + (rows * cols), cells);
}


Field::Field(Field&& other_field): rows(0), cols(0), start_position(Vector(0, 0)), finish_position(Vector(0, 0)), cells(nullptr){
    std::swap(rows, other_field.rows);
    std::swap(cols, other_field.cols);
    std::swap(start_position, other_field.start_position);
    std::swap(finish_position, other_field.finish_position);
    std::swap(cells, other_field.cells);// так как rvalue сам удалится
}


Field& Field::operator = (const Field& other_field){
    Field temp(other_field);
    std::swap(rows, temp.rows);
    std::swap(cols, temp.cols);
    std::swap(start_position, temp.start_position);
    std::swap(finish_position, temp.finish_position);
    std::swap(cells, temp.cells);
    return *this;
}


Field& Field::operator = (Field&& other_field){
    if(this != &other_field){
        std::swap(rows, other_field.rows);
        std::swap(cols, other_field.cols);
        std::swap(start_position, other_field.start_position);
        std::swap(finish_position, other_field.finish_position);
        std::swap(cells, other_field.cells);
    }
    return *this;
}


FieldCell& Field::getCell(const Vector& position){
    return cells[position.y * cols + position.x];
}


void Field::setStart_position(const Vector& start_position){
    this->start_position = start_position;
}


void Field::setFinish_position(const Vector& finish_position){
    this->finish_position = finish_position;
}


bool Field::RandomDecision(){
    int x = rand();
    return x % 2;
}

Vector Field::GetRandomCellFromSet(std::set<Vector>& cells){
    int index = rand() % cells.size();
    if(cells.size() == 1) index = 0;
    auto it = cells.begin();
    for(int k = 0; k < index; k++) it++;
    return *it;
}

void Field::GenerateMaze(int seed){
    srand(seed);
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < cols; j++){
            if(i == 1 && j > 0 && j < cols - 1) Field::getCell(Vector(j, i)).setCross_active(1);
            else if(i % 2 == 0) Field::getCell(Vector(j, i)).setCross_active(0);
            else if(j % 2 == 0) Field::getCell(Vector(j, i)).setCross_active(0);
            else if(i % 2 == 1 && j % 2 == 1) Field::getCell(Vector(j, i)).setCross_active(1);
            else Field::getCell(Vector(j, i)).setCross_active(0);
        }
    }
    std::set<Vector> maze_cells;
    int maze_width = cols - 1;
    int maze_height = rows - 1;
    int current_row = 3;
    int current_col = 1;
    Vector current_cell;
    while(true){
        current_cell = Vector(current_col, current_row);
        maze_cells.insert(current_cell);
        if(RandomDecision() == true && (current_col + 2 < maze_width)){
            Field::getCell(Vector(current_col + 1, current_row)).setCross_active(1); // break right wall
            current_col += 2; // move right
        }
        else{
            Vector random_cell = GetRandomCellFromSet(maze_cells);
            Field::getCell(Vector(random_cell.x, random_cell.y - 1)).setCross_active(1); // break upper wall
            if(current_col + 2 < maze_width) current_col += 2;
            else if(current_row + 2 >= maze_height) break;
            else{
                current_row += 2;
                current_col = 1;
            }
            maze_cells.erase(maze_cells.begin(), maze_cells.end());
        }
    }
}


Vector Field::size() const{
    return Vector(cols, rows);
}


Vector Field::getStart_position() const{
    return start_position;
}


Vector Field::getFinish_position() const{
    return finish_position;
}


Field::~Field(){
    delete[] cells;
}
