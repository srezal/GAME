#ifndef GAME_KEYLISTENERINTERFACE_H
#define GAME_KEYLISTENERINTERFACE_H


#include <iostream>


class KeyListenerInterface{
public:
    virtual ~KeyListenerInterface(){}
    virtual char ReadChar() = 0; 
    virtual std::string ReadString() = 0;
};


#endif //GAME_KEYLISTENERINTERFACE_H