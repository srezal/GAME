#include "PlayerManager.h"


PlayerManager::PlayerManager(Field& field, Player& player, const Vector& coord) :
        field(field),
        player(player),
        coord(Vector(coord.x * 2 + 1, coord.y * 2 + 1, {MIN_BORDER, field.size().x - 1},{MIN_BORDER, field.size().y - 1})),
        light_controller(LightController()),
        win(false) {
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
    light_controller.removeLight(field, getCoord(), player.getVision_distane());
    coord = newCoord;
    light_controller.setLight(field, coord, player.getVision_distane());
}

void PlayerManager::tpPlayerToStartPosition(){
    PlayerManager::setCoord(field.getStart_position());
}

void PlayerManager::setHas_key(bool value){
    player.setHas_key(value);
}

void PlayerManager::setKnow_where_is_exit(bool value){
    player.setKnow_where_is_exit(value);
}


bool PlayerManager::isWin() const{
    return win;
}


unsigned int PlayerManager::getHealth() const{
    return player.getHealth();
}


void PlayerManager::DecreaseVision(unsigned int k){
    player.setVision_distance(player.getVision_distane() / 2);
}

void PlayerManager::changeCoord(Direction dir) {
    Vector newCoord = getCoord();
    switch (dir) {
        case Direction::UP:
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
    if(candidate_cell.isCross_active()){ // если клетка проходима
        setCoord(newCoord);
        if(candidate_cell.has_event()){
            candidate_cell.getEventInterface().action(*this);;
            candidate_cell.setEventInterface(nullptr);
        }
    }
    else if(newCoord == field.getFinish_position()){
        if(player.Has_key()){
            win = true;
        }
    }
}
