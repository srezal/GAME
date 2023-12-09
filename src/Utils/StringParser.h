#ifndef GAME_STRINGPARSER_H
#define GAME_STRINGPARSER_H


#include <string>
#include <vector>


class StringParser{
public:
    std::vector<std::string> SplitString(std::string s, std::string delimiter); 
};


#endif //GAME_STRINGPARSER_H