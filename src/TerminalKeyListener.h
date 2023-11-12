#ifndef GAME_TERMINALKEYLISTENER_H
#define GAME_TERMINALKEYLISTENER_H


#include "KeyListenerInterface.h"


class TerminalKeyListener: public KeyListenerInterface{
public:
    TerminalKeyListener();
    char ReadChar() override;
    std::string ReadString() override;
    ~TerminalKeyListener() {};
};


#endif //GAME_TERMINALKEYLISTENER_H