#include "PlayerWinMessage.h"



PlayerWinMessage::PlayerWinMessage(const unsigned int playerHp): playerHp(playerHp){
}


std::ostream& PlayerWinMessage::to_stream(std::ostream& stream){
    stream << playerHp;
    return stream;
}


std::string PlayerWinMessage::AcceptVisitor(MessageVisitor& visitor){
    return visitor.visit(*this);
}