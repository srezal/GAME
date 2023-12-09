#include "Logger.h"
#include <iostream>


void Logger::AddOstream(std::ostream* stream){
    ostreams_vector.push_back(stream);
}


std::ostream& operator<<(std::ostream& ostream, MessageInterface& imsg_ptr){
    return imsg_ptr.to_stream(ostream);
}


void Logger::MakeLog(MessageInterface* msg_interface){
    std::string msg_prefix = msg_interface->AcceptVisitor(visitor);
    for(int i = 0; i < ostreams_vector.size(); i++){
        *(ostreams_vector[i]) << msg_prefix << *msg_interface << "\n";
    }
}