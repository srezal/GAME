#ifndef GAME_INPUTMANAGERINTERFACE_H
#define GAME_INPUTMANAGERINTERFACE_H


#include <string>


class InputManagerInterface{
public:
    virtual ~InputManagerInterface(){};
    virtual char GetChar() = 0; 
    virtual std::string GetString() = 0;
};


#endif //GAME_INPUTMANAGERINTERFACE_H