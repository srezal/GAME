#include "FileInputManager.h"


FileInputManager::FileInputManager(){
    input.open(CONTROL_TXT_PATH);
}


char FileInputManager::GetChar(){
    char input_ch;
    input >> input_ch;
    return input_ch;
}


std::string FileInputManager::GetString(){
    std::string str;
    std::getline(input, str);
    return str;
}


FileInputManager::~FileInputManager(){
}