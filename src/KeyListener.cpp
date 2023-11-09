#include "KeyListener.h"
#include <iostream>


char KeyListener::listen(){
    system("stty raw");
    char key = getchar();
    system("stty cooked");
    return key;
}