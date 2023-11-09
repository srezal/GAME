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


Field::Field(unsigned int width, unsigned int height, const Vector& start_position, const Vector& finish_position){
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


void Field::setCellsCrossActiveFromMask(int* mask){
    for(int i = 0; i < rows * cols; i++) cells[i].setCross_active(mask[i]);
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
