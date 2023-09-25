#ifndef GAME_PLAYER_H
#define GAME_PLAYER_H


#include <cinttypes>
#include <algorithm>


class Player {
private:
    unsigned int health;
    unsigned int score;
public:
    Player(unsigned int health, unsigned int score);
    unsigned int getHealth() const;
    unsigned int getScore() const;
    void setHealth(int newHealth);
    void setScore(unsigned int newScore);
};


#endif //GAME_PLAYER_H
