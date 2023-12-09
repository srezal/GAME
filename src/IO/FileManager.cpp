#include "FileManager.h"


bool FileManager::Open(std::string file_path, FileOpenModes mode){
    if(mode == FileOpenModes::READ){
        input_stream.open(file_path);
        if(!input_stream) return 1; // error
        return 0; // successfully
    }
    else if(mode == FileOpenModes::WRITE){
        output_stream.open(file_path);
        if(!output_stream) return 1; // error
        return 0; // successfully
    }
}


char FileManager::ReadChar(){
    char value;
    if(input_stream) input_stream >> value;
    return value;
}


bool FileManager::ReadString(std::string& dst_str){
    if(!input_stream) return false;
    if(!input_stream.eof()){
        std::getline(input_stream, dst_str);
        return true;
    }
    return false;
}


void FileManager::Write(std::string text){
    if(output_stream) output_stream << text;
}


void FileManager::Close(){
    if(input_stream) input_stream.close();
    if(output_stream) output_stream.close();
}


std::ofstream* FileManager::GetOutputStream(){
    return &output_stream;
}