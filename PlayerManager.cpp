#include "PlayerManager.h"

PlayerManager::PlayerManager(Player& player, const Vector& coord) :
        player(player), coord(coord) {
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
            newCoord += Vector{0, 1};
            break;
        case Direction::DOWN:
            newCoord += Vector{0, -1};
            break;
        case Direction::LEFT:
            newCoord += Vector{-1, 0};
            break;
        case Direction::RIGHT:
            newCoord += Vector{1, 0};
            break;
    }

    setCoord(Vector(newCoord.x, newCoord.y,{0, 100},{0, 100}));
}
