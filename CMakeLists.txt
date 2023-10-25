cmake_minimum_required(VERSION 3.24)
project(GAME)

set(CMAKE_CXX_STANDARD 17)

add_executable(GAME main.cpp Player.cpp PlayerManager.cpp Vector.cpp FieldCell.cpp Field.cpp Printer.cpp KeyListener.cpp PickUpCoinEvent.cpp FieldCreator.cpp TrapEvent.cpp TeleportEvent.cpp PrintToConsoleVisitor.cpp MazeGenerator.cpp Player.h PlayerManager.h Direction.h Vector.h  FieldCell.h Field.h EventInterface.h Printer.h KeyListener.h PickUpCoinEvent.h FieldCreator.h TrapEvent.h TeleportEvent.h EventVisitorInterface.h PrintToConsoleVisitor.h MazeGenerator.h)

target_link_libraries(GAME ncurses)
