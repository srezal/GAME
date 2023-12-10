#include "CommandManager.h"
#include <iostream>
#include <algorithm>


CommandsEnum CommandManager::GetCommand(Config& conf, char& key){
    key = conf.INPUT_MANAGER_PTR->GetChar();
    if(conf.COMMANDS_KEYS.find(key) == conf.COMMANDS_KEYS.end()){
        return CommandsEnum::NULL_COMMAND;
    }
    CommandsEnum command = conf.COMMANDS_KEYS[key];
    return command;
}


void CommandManager::SetDefaultKeyBindings(Config& conf){
    conf.COMMANDS_KEYS.clear();
    conf.COMMANDS_KEYS['w'] = CommandsEnum::GO_UP;   // 
    conf.COMMANDS_KEYS['a'] = CommandsEnum::GO_LEFT; // 
    conf.COMMANDS_KEYS['s'] = CommandsEnum::GO_DOWN; // ---- default keys binds
    conf.COMMANDS_KEYS['d'] = CommandsEnum::GO_RIGHT;//
    conf.COMMANDS_KEYS['.'] = CommandsEnum::EXIT;    //
}


void CommandManager::SetCommandFromSplittedString(Config& conf, std::vector<std::string>& splitted_str){
    std::string token = splitted_str[0];
    std::string key =  splitted_str[1];
    if(token == "up") conf.COMMANDS_KEYS[key[0]] = CommandsEnum::GO_UP;
    else if(token == "down") conf.COMMANDS_KEYS[key[0]] = CommandsEnum::GO_DOWN;
    else if(token == "right") conf.COMMANDS_KEYS[key[0]] = CommandsEnum::GO_RIGHT;
    else if(token == "left") conf.COMMANDS_KEYS[key[0]] = CommandsEnum::GO_LEFT;
    else if(token == "exit") conf.COMMANDS_KEYS[key[0]] = CommandsEnum::EXIT;
}


void CommandManager::CheckCommandsKeys(Config& conf){
    std::vector<CommandsEnum> already_setted_commands;
    for(std::map<char, CommandsEnum>::iterator it = conf.COMMANDS_KEYS.begin(); it != conf.COMMANDS_KEYS.end(); ++it) {
        CommandsEnum command = it->second;
        if((std::find(already_setted_commands.begin(), already_setted_commands.end(), command)) != already_setted_commands.end()){
            conf.OUTPUT_MANAGER_PTR->sendMsg("Too much commands on one key! Default keybindings will be set!");
            SetDefaultKeyBindings(conf);
            return;
        }
        already_setted_commands.push_back(command);
    }
    if((std::find(already_setted_commands.begin(), already_setted_commands.end(), CommandsEnum::GO_UP)) == already_setted_commands.end()){
        conf.COMMANDS_KEYS['w'] = CommandsEnum::GO_UP;
    }
    if((std::find(already_setted_commands.begin(), already_setted_commands.end(), CommandsEnum::GO_LEFT)) == already_setted_commands.end()){
        conf.COMMANDS_KEYS['a'] = CommandsEnum::GO_LEFT;
    }
    if((std::find(already_setted_commands.begin(), already_setted_commands.end(), CommandsEnum::GO_RIGHT)) == already_setted_commands.end()){
        conf.COMMANDS_KEYS['d'] = CommandsEnum::GO_RIGHT;
    }
    if((std::find(already_setted_commands.begin(), already_setted_commands.end(), CommandsEnum::GO_DOWN)) == already_setted_commands.end()){
        conf.COMMANDS_KEYS['s'] = CommandsEnum::GO_DOWN;
    }
    if((std::find(already_setted_commands.begin(), already_setted_commands.end(), CommandsEnum::EXIT)) == already_setted_commands.end()){
        conf.COMMANDS_KEYS['.'] = CommandsEnum::EXIT;
    }
}