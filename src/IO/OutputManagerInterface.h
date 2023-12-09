#ifndef GAME_OUTPUTMANAGERINTERFACE_H
#define GAME_OUTPUTMANAGERINTERFACE_H


#include <string>


class OutputManagerInterface{
public:
    virtual ~OutputManagerInterface(){};
    virtual void sendMsg(std::string) = 0; 
};


#endif //GAME_OUTPUTMANAGERINTERFACE_H