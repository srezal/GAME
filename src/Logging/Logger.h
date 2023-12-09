#ifndef GAME_LOGGER_H
#define GAME_LOGGER_H

#include <vector>
#include "../IO/OutputManagerInterface.h"
#include "MessageInterface.h"
#include "MessageVisitor.h"

class Logger{
private:
    std::vector<std::ostream*> ostreams_vector;
    MessageVisitor visitor;
public:
    void AddOstream(std::ostream*);
    void MakeLog(MessageInterface*);
};



#endif //GAME_LOGGER_H
