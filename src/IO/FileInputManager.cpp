#include "FileInputManager.h"


FileInputManager::FileInputManager(){
    file_manager.Open(CONTROL_TXT_PATH, FileOpenModes::READ);
}


char FileInputManager::GetChar(){
    return file_manager.ReadChar();
}


std::string FileInputManager::GetString(){
    std::string str;
    file_manager.ReadString(str);
    return str;
}


FileInputManager::~FileInputManager(){

}