#include "Config.h"
#include "../IO/TerminalInputManager.h"
#include "../IO/FileInputManager.h"
#include "../IO/TerminalOutputManager.h"
#include "../IO/FileOpenModes.h"
#include "../IO/FileManager.h"
#include "../Utils/StringParser.h"
#include "../Game/CommandManager.h"


#include <iostream>


Config::Config(){
    INPUT_MANAGER_PTR = new TerminalInputManager();
    OUTPUT_MANAGER_PTR = new TerminalOutputManager();
    LEVEL_TYPE = LevelType::NULL_LEVEL; // null before setting
    commands_strings[CommandsEnum::GO_UP] = "go_up";
    commands_strings[CommandsEnum::GO_LEFT] = "go_left";
    commands_strings[CommandsEnum::GO_RIGHT] = "go_right";
    commands_strings[CommandsEnum::GO_DOWN] = "go_down";
    commands_strings[CommandsEnum::EXIT] = "exit";
    SetLevelType();
    SetInputManager();
    ReadControlSettingsFromFile();
    SetLoggerTerminalOutput();
    SetLoggerFileOutput();
}


void Config::SetLevelType(){
    OUTPUT_MANAGER_PTR->sendMsg("Choose level type 1(Maze), 2(Arena): ");
    char input_char = INPUT_MANAGER_PTR->GetChar();
    switch(input_char){
        case '1':
            LEVEL_TYPE = LevelType::MAZE;
            break;
        case '2':
            LEVEL_TYPE = LevelType::ARENA;
            break; 
        default:
            break;   
    };
    if(LEVEL_TYPE == LevelType::NULL_LEVEL) SetLevelType();
}


void Config::SetInputManager(){
    OUTPUT_MANAGER_PTR->sendMsg("Choose input type 1(Terminal), 2(File): ");
    InputManagerInterface* NEW_INPUT_MANAGER_PTR = nullptr;
    char input_char = INPUT_MANAGER_PTR->GetChar();
    switch(input_char){
        case '1':
            NEW_INPUT_MANAGER_PTR = new TerminalInputManager;
            break;
        case '2':
            NEW_INPUT_MANAGER_PTR = new FileInputManager;
            break; 
        default:
            break;   
    };
    if(NEW_INPUT_MANAGER_PTR == nullptr) SetLevelType();
    delete INPUT_MANAGER_PTR;
    INPUT_MANAGER_PTR = NEW_INPUT_MANAGER_PTR;
}


void Config::SetOutputManager(){}


void Config::SetLoggerTerminalOutput(){
    OUTPUT_MANAGER_PTR->sendMsg("Logs in Terminal 1(Yes), any other key(No): ");
    char input_char = INPUT_MANAGER_PTR->GetChar();
    if(input_char == '1') logger.AddOstream(&std::cout);
}


void Config::SetLoggerFileOutput(){
    OUTPUT_MANAGER_PTR->sendMsg("Logs in File 1(Yes), any other key(No): ");
    char input_char = INPUT_MANAGER_PTR->GetChar();
    if(input_char == '1'){
        file_manager.Open(LOGS_TXT_PATH, FileOpenModes::WRITE);
        logger.AddOstream(file_manager.GetOutputStream());
    }
}


void Config::ReadControlSettingsFromFile(){
    CommandManager comm_manager = CommandManager();
    FileManager file_manager = FileManager();
    StringParser string_parser = StringParser();
    file_manager.Open(SETTING_TXT_PATH, FileOpenModes::READ);
    std::string str;
    std::vector<std::string> splitted_string;
    while(file_manager.ReadString(str)){
        splitted_string = string_parser.SplitString(str, " ");
        comm_manager.SetCommandFromSplittedString(*this, splitted_string);
    }
    file_manager.Close();
    comm_manager.CheckCommandsKeys(*this);
}


Config::~Config(){
    delete INPUT_MANAGER_PTR;
    delete OUTPUT_MANAGER_PTR;
    file_manager.Close();
}