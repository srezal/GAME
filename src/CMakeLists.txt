cmake_minimum_required(VERSION 3.24)
project(GAME)

set(CMAKE_CXX_STANDARD 17)

add_executable(GAME main.cpp Player.cpp PlayerManager.cpp Vector.cpp FieldCell.cpp Field.cpp Printer.cpp Events/PickUpCoinEvent.cpp FieldCreator.cpp Events/TrapEvent.cpp Events/TeleportEvent.cpp PrintToConsoleVisitor.cpp MazeGenerator.cpp LightController.cpp Events/PickUpKeyEvent.cpp Events/ShowExitEvent.cpp Events/BlindnessEvent.cpp TerminalKeyListener.cpp Game.cpp Commands/PlayerGoDownCommand.cpp Commands/PlayerGoUpCommand.cpp Commands/PlayerGoLeftCommand.cpp Commands/PlayerGoRightCommand.cpp FileKeyListener.cpp Player.h PlayerManager.h Direction.h Vector.h  FieldCell.h Field.h Events/EventInterface.h Printer.h Events/PickUpCoinEvent.h FieldCreator.h Events/TrapEvent.h Events/TeleportEvent.h EventVisitorInterface.h PrintToConsoleVisitor.h MazeGenerator.h LightController.h Events/PickUpKeyEvent.h Events/ShowExitEvent.h KeyListenerInterface.h TerminalKeyListener.h Game.h Commands/PlayerCommandInterface.h Commands/PlayerGoDownCommand.h Commands/PlayerGoUpCommand.h Commands/PlayerGoLeftCommand.h Commands/PlayerGoRightCommand.h FileKeyListener.h)

target_link_libraries(GAME ncurses)
