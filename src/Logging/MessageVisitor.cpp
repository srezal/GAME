#include "MessageVisitor.h"


std::string MessageVisitor::visit(GameStartMessage& msg_obj){
    return "Start a new game. Field size and players start position: ";
}


std::string MessageVisitor::visit(PlayerWinMessage& msg_obj){
    return "Player win. Players hp: ";
}


std::string MessageVisitor::visit(KeyPressedMessage& msg_obj){
    return "Key pressed: ";
}


std::string MessageVisitor::visit(KeyPressedAndCommandRunMessage& msg_obj){
    return "Key pressed and command run: ";
}


std::string MessageVisitor::visit(PlayerWastedMessage& msg_obj){
    return "Player wasted. Last cell coords: ";
}