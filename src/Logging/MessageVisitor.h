#ifndef GAME_MESSAGEVISITOR_H
#define GAME_MESSAGEVISITOR_H

#include <string>

class PlayerWinMessage;
class GameStartMessage;
class KeyPressedMessage;
class KeyPressedAndCommandRunMessage;
class PlayerWastedMessage;


class MessageVisitor{
public:
    std::string visit(PlayerWinMessage&);
    std::string visit(GameStartMessage&);
    std::string visit(KeyPressedMessage&);
    std::string visit(KeyPressedAndCommandRunMessage&);
    std::string visit(PlayerWastedMessage&);
};


#endif //GAME_MESSAGEVISITOR_H