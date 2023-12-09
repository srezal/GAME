#ifndef GAME_MESSAGEINTERFACE_H
#define GAME_MESSAGEINTERFACE_H

#include <ostream>


#include "MessageVisitor.h"


class MessageInterface{
public:
    virtual std::string AcceptVisitor(MessageVisitor&) = 0;
    virtual std::ostream& to_stream(std::ostream&) = 0;
    ~MessageInterface(){}
};

#endif //GAME_MESSAGEINTERFACE_H