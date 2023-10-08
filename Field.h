#ifndef GAME_FIELD_H
#define GAME_FIELD_H


#define MIN_BORDER 0
#define MAX_BORDER 100


#include "FieldCell.h"
#include "Vector.h"


class Field{
private:
    FieldCell* cells;
    unsigned int rows;
    unsigned int cols;
    Vector start_position;
    Vector finish_position;
public:
    Field();
    Field(unsigned int rows, unsigned int cols, const Vector& start_position, const Vector& finish_position);
    Field(const Field& other_field);
    Field(Field&& other_field);
    Field& operator = (const Field& other_field);
    Field& operator = (Field&& other_field);
    FieldCell& getCell(const Vector& position);
    void setStart_position(const Vector& start_position);
    void setFinish_position(const Vector& finish_position);
    Vector size() const;
    Vector getStart_position() const;
    Vector getFinish_position() const;
    ~Field();
};


#endif //GAME_FIELD_H
