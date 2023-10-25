#include "PrintToConsoleVisitor.h"
#include "TeleportEvent.h"
#include "TrapEvent.h"
#include "PickUpCoinEvent.h"


PrintToConsoleVisitor::PrintToConsoleVisitor(Printer& printer): printer(printer){}


void PrintToConsoleVisitor::visit(TeleportEvent teleport_event){
    printer.printTeleport();
}


void PrintToConsoleVisitor::visit(TrapEvent trap_event){
    printer.printTrap();
}


void PrintToConsoleVisitor::visit(PickUpCoinEvent pickUpCoin_event){
    printer.printCoin();
}