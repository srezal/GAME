#ifndef GAME_MESSAGEINTERFACE_H
#define GAME_MESSAGEINTERFACE_H

#include <ostream>


class MessageInterface{
public:
    virtual std::string getStringMessage() = 0;
    virtual ~MessageInterface(){}
    friend std::ostream& operator<<(std::ostream& out, MessageInterface&);
};

#endif //GAME_MESSAGEINTERFACE_H