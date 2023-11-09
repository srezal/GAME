#include "ShowExitEvent.h"


EventInterface* ShowExitEvent::copy(){
    return new ShowExitEvent();
}


void ShowExitEvent::action(PlayerManager& player_manager){
    player_manager.setKnow_where_is_exit(1);
}


void ShowExitEvent::AcceptVisitor(EventVisitorInterface& visitor){
    visitor.visit(*this); // Superhard to understand single line of code 
}


ShowExitEvent::~ShowExitEvent(){}