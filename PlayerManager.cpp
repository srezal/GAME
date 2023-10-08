#include "PlayerManager.h"


PlayerManager::PlayerManager(Field& field, Player& player, const Vector& coord) :
        field(field), player(player), coord(Vector(coord.x, coord.y, {MIN_BORDER, field.size().x - 1},{MIN_BORDER, field.size().y - 1})) {
}

void PlayerManager::addHealth(int addition) {
    player.setHealth(player.getHealth() + addition);
}

void PlayerManager::addScore(unsigned int addition) {
    player.setScore(player.getScore() + addition);
}

const Vector& PlayerManager::getCoord() {
    return coord;
}

void PlayerManager::setCoord(const Vector& newCoord) {
    coord = newCoord;
}

void PlayerManager::changeCoord(Direction dir) {
    Vector newCoord = getCoord();
    switch (dir) {
        case Direction::TOP:
            newCoord += Vector{0, -1};
            break;
        case Direction::DOWN:
            newCoord += Vector{0, 1};
            break;
        case Direction::LEFT:
            newCoord += Vector{-1, 0};
            break;
        case Direction::RIGHT:
            newCoord += Vector{1, 0};
            break;
    }
    if(field.getCell(newCoord).getCross_active() == true){ // если клетка проходима
        setCoord(Vector(newCoord.x, newCoord.y,{MIN_BORDER, field.size().x - 1}, {MIN_BORDER, field.size().y - 1})); 
    }
}
