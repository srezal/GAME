#include "Player.h"


unsigned int Player::getHealth() const {
    return health;
}

unsigned int Player::getScore() const {
    return score;
}

unsigned int Player::getVision_distane() const{
    return vision_distance;
}

bool Player::Has_key() const{
    return has_key;
}

bool Player::isKnow_where_is_exit() const{
    return know_where_is_exit;
}

void Player::setHealth(int newHealth) {
    health = std::clamp(newHealth, 0, MAX_HEALTH);
}

void Player::setScore(int newScore) {
    score = std::clamp(newScore, 0, MAX_SCORE);
}

void Player::setHas_key(bool value){
    has_key = value;
}

void Player::setKnow_where_is_exit(bool value){
    know_where_is_exit = value;
}

void Player::setVision_distance(unsigned int value){
    vision_distance = value;
}

Player::Player(unsigned int health, unsigned int score, unsigned int vision_distance) :
        health(health),
        score(score),
        vision_distance(vision_distance),
        has_key(0),
        know_where_is_exit(0){
}