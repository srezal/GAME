#include "FileKeyListener.h"
#include <iostream>


FileKeyListener::FileKeyListener(std::istream* input_stream_ptr): input_stream_ptr(input_stream_ptr){}


char FileKeyListener::ReadChar(){
    char key;
    *input_stream_ptr >> key;
    return key;
}


std::string FileKeyListener::ReadString(){
    std::string str;
    std::getline(*input_stream_ptr, str);
    return str;
}


FileKeyListener::~FileKeyListener(){
    delete input_stream_ptr;
}