#include "PlayerManager.h"


PlayerManager::PlayerManager(Field& field, Player& player, const Vector& coord) :
        field(field), player(player), coord(Vector(coord.x * 2 + 1, coord.y * 2 + 1, {MIN_BORDER, field.size().x - 1},{MIN_BORDER, field.size().y - 1})) {
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
    newCoord = Vector(newCoord.x, newCoord.y, {MIN_BORDER, field.size().x - 1}, {MIN_BORDER, field.size().y - 1});
    FieldCell& candidate_cell = field.getCell(newCoord);
    if(candidate_cell.getCross_active() == true){ // если клетка проходима
        setCoord(newCoord);
        if(candidate_cell.has_event() == true){
            EventInterface& event = candidate_cell.getEventInterface();
            event.action();
            if(event.is_finite() == true) candidate_cell.setEventInterface(nullptr);
        }
    }
}
