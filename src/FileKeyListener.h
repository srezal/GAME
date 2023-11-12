#ifndef GAME_FILEKEYLISTENER_H
#define GAME_FILEKEYLISTENER_H


#include "KeyListenerInterface.h"


class FileKeyListener: public KeyListenerInterface{
private:
    std::istream* input_stream_ptr;
public:
    FileKeyListener(std::istream*);
    char ReadChar() override;
    std::string ReadString() override;
    ~FileKeyListener();
};


#endif //GAME_TERMINALKEYLISTENER_H