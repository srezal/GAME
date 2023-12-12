#include "Game.h"
#include <iostream>
#include "../IO/TerminalInputManager.h"
#include "../IO/FileInputManager.h"
#include <fstream>
#include "../Config/Config.h"
#include "../ActionManager/ActionManager.h"
#include "../Logging/GameStartMessage.h"


Game::Game(Config& conf): conf(conf){
}


void Game::RestartGame(){
    conf.LEVEL_TYPE = LevelType::NULL_LEVEL;
    conf.SetLevelType();
    StartGame();
}


void Game::EndGame(){
    conf.OUTPUT_MANAGER_PTR->sendMsg("see you soon");
}


void Game::StartGame(){
    Player player = Player(50, 0, 4);
    Field field = FieldCreator().create(conf.LEVEL_TYPE, Vector(5, 5));
    PlayerManager pm = PlayerManager(field, player, Vector(0, 0));
    CommandManager commands_manager = CommandManager();
    ActionManager action_manager = ActionManager(conf, pm, field, player);
    GameState game_state = GameState::PLAYING;
    GameStartMessage start_msg = GameStartMessage(field.size(), pm.getCoord());
    conf.loggers_manager.MakeLog(start_msg);
    while(game_state == GameState::PLAYING){
        game_state = action_manager.GameIteration();
    }
    if(game_state == GameState::EXIT){
        EndGame();
        return;
    }
    RestartGame();
}