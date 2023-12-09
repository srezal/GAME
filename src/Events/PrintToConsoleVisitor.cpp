#include "PrintToConsoleVisitor.h"
#include "TeleportEvent.h"
#include "TrapEvent.h"
#include "PickUpCoinEvent.h"
#include "PickUpKeyEvent.h"
#include "ShowExitEvent.h"
#include "BlindnessEvent.h"


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


void PrintToConsoleVisitor::visit(PickUpKeyEvent pickUpKey_event){
    printer.printKey();
}


void PrintToConsoleVisitor::visit(ShowExitEvent showExit_event){
    printer.printEye();
}


void PrintToConsoleVisitor::visit(BlindnessEvent blindness_event){
    printer.printBlindnessPill();
}