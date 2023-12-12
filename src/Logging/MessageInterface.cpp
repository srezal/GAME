#include "MessageInterface.h"


std::ostream& operator<<(std::ostream& out, MessageInterface& imsg){
    out << imsg.getStringMessage();
    return out;
}