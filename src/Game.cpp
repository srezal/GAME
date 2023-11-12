#include "Game.h"
#include <iostream>
#include "TerminalKeyListener.h"
#include "FileKeyListener.h"
#include "Commands/PlayerGoDownCommand.h"
#include "Commands/PlayerGoUpCommand.h"
#include "Commands/PlayerGoRightCommand.h"
#include "Commands/PlayerGoLeftCommand.h"
#include <fstream>


Game::Game(){
    level_type = LevelType::NULL_LEVEL;
    key_listener_ptr = new TerminalKeyListener();
    while(level_type == LevelType::NULL_LEVEL){
        SetLevel_type();
    }
    ChangeKeyListener();
    StartGame();
}


void Game::SetLevel_type(){
    std::cout << "\nChoose level type 1(Maze), 2(Arena): ";
    switch(key_listener_ptr->ReadChar()){
        case '1':
            level_type = LevelType::MAZE;
            break;
        case '2':
            level_type = LevelType::ARENA;
            break; 
        default:
            break;   
    };
}


void Game::ChangeKeyListener(){
    std::cout << "\nChoose control type 1(from Terminal), 2(from File): ";
    switch(key_listener_ptr->ReadChar()){
        case '1':
            delete key_listener_ptr;
            key_listener_ptr = new TerminalKeyListener();
            break;
        case '2':{
            delete key_listener_ptr;
            std::ifstream* file_input_stream_ptr = new std::ifstream;
            file_input_stream_ptr->open("/home/srezal/study/GAME/src/control.txt");
            key_listener_ptr = new FileKeyListener(file_input_stream_ptr);
            break; 
        };
        default:
            break;   
    };
}


PlayerCommandInterface* Game::GetCommand(){
    PlayerCommandInterface* command = nullptr;
    char KEY = key_listener_ptr->ReadChar();
    switch(KEY){
        case 'w':
            command = new PlayerGoUpCommand();
            break;
        case 's':
            command = new PlayerGoDownCommand();
            break;
        case 'd':
            command = new PlayerGoRightCommand();
            break;
        case 'a':
            command = new PlayerGoLeftCommand();
            break;
        case '.':
            exit(0);
    };
    return command;
}


void Game::StartGame(){
    Player player(50, 0, 4);
    Field field = FieldCreator().create(level_type, Vector(6, 6));
    PlayerManager pm = PlayerManager(field, player, Vector(0, 0));
    Printer printer(field, pm, player);
    printer.clean();
    printer.print();
    while(true){
        PlayerCommandInterface* command = GetCommand();
        if(command != nullptr) command->Run(pm);
        delete command;
        printer.clean();
        if(pm.isWin()){
            printer.printMsg("[WIN]");
            return;
        }
        if(pm.getHealth() == 0){
            printer.printMsg("[WASTED]");
            return;
        }
        printer.print();
    }
}


Game::~Game(){
    delete key_listener_ptr;
}