#include "Player.h"


unsigned int Player::getHealth() const {
    return health;
}

unsigned int Player::getScore() const {
    return score;
}

void Player::setHealth(int newHealth) {
    health = std::clamp(newHealth, 0, 100);
}

void Player::setScore(unsigned int newScore) {
    score = newScore;
}

Player::Player(unsigned int health, unsigned int score) :
        health(health),
        score(score){
}