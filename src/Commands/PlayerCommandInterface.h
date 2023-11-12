#ifndef GAME_PLAYERCOMMANDINTERFACE_H
#define GAME_PLAYERCOMMANDINTERFACE_H


class PlayerManager;


class PlayerCommandInterface{
public:
    virtual void Run(PlayerManager&) = 0;
    virtual ~PlayerCommandInterface(){};
};


#endif //GAME_PLAYERCOMMANDINTERFACE_H