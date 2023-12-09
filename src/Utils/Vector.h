#ifndef GAME_VECTOR_H
#define GAME_VECTOR_H

#include <utility>
#include <cinttypes>
#include <algorithm>

struct Vector {
    int x;
    int y;

    Vector() = default;

    Vector(int x, int y);

    Vector(int x, int y, const std::pair<int, int> &restrictX, const std::pair<int, int> &restrictY);

    Vector operator+(const Vector &other) const;

    bool operator==(const Vector& other) const;

    bool operator<(const Vector& other) const;

    void operator+=(const Vector &other);
};

#endif //GAME_VECTOR_H
