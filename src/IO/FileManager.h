#ifndef GAME_FILEMANAGER_H
#define GAME_FILEMANAGER_H


#include <fstream>
#include "FileOpenModes.h"


class FileManager{
private:
    std::ifstream input_stream;
    std::ofstream output_stream;
public:
    bool Open(std::string, FileOpenModes);
    char ReadChar();
    bool ReadString(std::string&);
    void Write(std::string);
    std::ofstream* GetOutputStream();
    void Close();
};


#endif //GAME_FILEREADER_H