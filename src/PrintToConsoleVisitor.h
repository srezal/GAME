#ifndef GAME_PRINTTOCONSOLEVISITOR_H
#define GAME_PRINTTOCONSOLEVISITOR_H


#include "EventVisitorInterface.h"
#include "Printer.h"


class PrintToConsoleVisitor: public EventVisitorInterface{
private:
    Printer& printer;
public:
    PrintToConsoleVisitor(Printer&);
    void visit(TeleportEvent) override;
    void visit(TrapEvent) override;
    void visit(PickUpCoinEvent) override;
    void visit(PickUpKeyEvent)override;
    void visit(ShowExitEvent)override;
    void visit(BlindnessEvent)override;
};


#endif //GAME_PRINTTOCONSOLEVISITOR_H