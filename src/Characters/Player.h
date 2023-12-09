#ifndef GAME_PLAYER_H
#define GAME_PLAYER_H


#define MAX_HEALTH 2000
#define MAX_SCORE 10000

#include <cinttypes>
#include <algorithm>


class Player {
private:
    unsigned int health;
    unsigned int score;
    unsigned int vision_distance;
    bool has_key;
    bool know_where_is_exit;
public:
    Player() = default;
    Player(unsigned int health, unsigned int score, unsigned int vision_distance);
    unsigned int getHealth() const;
    unsigned int getScore() const;
    unsigned int getVision_distane() const;
    bool isKnow_where_is_exit() const;
    bool Has_key() const;
    void setHealth(int newHealth);
    void setScore(int newScore);
    void setHas_key(bool has_key);
    void setKnow_where_is_exit(bool value);
    void setVision_distance(unsigned int value);
};


#endif //GAME_PLAYER_H
