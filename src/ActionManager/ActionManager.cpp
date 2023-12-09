#include "ActionManager.h"
#include <iostream>
#include "../Logging/PlayerWinMessage.h"
#include "../Logging/KeyPressedMessage.h"
#include "../Logging/KeyPressedAndCommandRunMessage.h"
#include "../Logging/PlayerWastedMessage.h"

ActionManager::ActionManager(Config& conf, PlayerManager& pm, Field& field, Player& player):
    conf(conf),
    field(field),
    player(player),
    pm(pm),
    printer(new Printer(field, pm, player)),
    exit(false),
    player_mooved(false){
        printer->print();
}


void ActionManager::RunCommand(CommandsEnum command){
    switch(command){
        case CommandsEnum::GO_RIGHT:
            pm.changeCoord(Direction::RIGHT);
            player_mooved = true;
            break;
        case CommandsEnum::GO_LEFT:
            player_mooved = true;
            pm.changeCoord(Direction::LEFT);
            break;
        case CommandsEnum::GO_UP:
            player_mooved = true;
            pm.changeCoord(Direction::UP);
            break;
        case CommandsEnum::GO_DOWN:
            player_mooved = true;
            pm.changeCoord(Direction::DOWN);
            break;
        case CommandsEnum::EXIT:
            exit = true;
            player_mooved = false;
            break;
        case CommandsEnum::NULL_COMMAND:
            player_mooved = false;
            break;
    };
}


GameState ActionManager::GameIteration(){
    char input_key;
    CommandsEnum command = command_manager.GetCommand(conf, input_key);
    RunCommand(command);
    if(player_mooved) printer->print();   
    if(command != CommandsEnum::NULL_COMMAND){
        KeyPressedAndCommandRunMessage key_pressed_and_command_run_msg = KeyPressedAndCommandRunMessage(input_key, conf.commands_strings[command]);
        conf.logger.MakeLog(&key_pressed_and_command_run_msg);
    } 
    else{
        KeyPressedMessage key_pressed_msg = KeyPressedMessage(input_key);
        conf.logger.MakeLog(&key_pressed_msg);
    }   
    if(exit) return GameState::EXIT;                                                                                 
    if(pm.isWin()){
        conf.OUTPUT_MANAGER_PTR->sendMsg("WIN");
        PlayerWinMessage player_win_msg = PlayerWinMessage(pm.getHealth());
        conf.logger.MakeLog(&player_win_msg);
        return GameState::COMPLETED;
    }
    if(pm.getHealth() == 0){
        conf.OUTPUT_MANAGER_PTR->sendMsg("WASTED");
        PlayerWastedMessage player_wasted_msg = PlayerWastedMessage(pm.getCoord());
        conf.logger.MakeLog(&player_wasted_msg);
        return GameState::COMPLETED;
    }
    return GameState::PLAYING;
}


ActionManager::~ActionManager(){
    delete printer;
}