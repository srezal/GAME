#include "Player.h"


unsigned int Player::getHealth() const {
    return health;
}

unsigned int Player::getScore() const {
    return score;
}

void Player::setHealth(int newHealth) {
    health = std::clamp(newHealth, 0, MAX_HEALTH);
}

void Player::setScore(int newScore) {
    score = std::clamp(newScore, 0, MAX_SCORE);
}

Player::Player(unsigned int health, unsigned int score) :
        health(health),
        score(score){
}