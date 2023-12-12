#include "PlayerWinMessage.h"



PlayerWinMessage::PlayerWinMessage(const unsigned int playerHp): playerHp(playerHp){
}


std::string PlayerWinMessage::getStringMessage(){
    return std::format("Player win with hp {}.", playerHp);
}