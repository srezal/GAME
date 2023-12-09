#ifndef GAME_FIELD_H
#define GAME_FIELD_H


#define MIN_BORDER 0
#define MAX_BORDER 1000
#define DEFAULT_SIZE 15


#include <set>
#include "FieldCell.h"
#include "../Utils/Vector.h"


class Field{
private:
    FieldCell* cells;
    unsigned int rows;
    unsigned int cols;
    Vector start_position;
    Vector finish_position;
    bool is_night;
public:
    Field();
    Field(unsigned int rows, unsigned int cols, const Vector& start_position, const Vector& finish_position, bool is_night = false);
    Field(const Field& other_field);
    Field(Field&& other_field);
    Field& operator = (const Field& other_field);
    Field& operator = (Field&& other_field);
    FieldCell& getCell(const Vector& position);
    void setStart_position(const Vector& start_position);
    void setFinish_position(const Vector& finish_position);
    void setCellsCrossActiveFromMask(int* mask);
    void setIs_night(bool value);
    Vector size() const;
    Vector getStart_position() const;
    Vector getFinish_position() const;
    bool getIs_night() const;
    ~Field();
};


#endif //GAME_FIELD_H
