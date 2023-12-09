#include "LightController.h"


void LightController::fillLight(Field& field, Vector current_coords, int distance){
    if(distance == 0) return;
    FieldCell& up_cell = field.getCell(current_coords + Vector{0, 1});
    FieldCell& down_cell = field.getCell(current_coords + Vector{0, -1});
    FieldCell& right_cell = field.getCell(current_coords + Vector{1, 0});
    FieldCell& left_cell = field.getCell(current_coords + Vector{-1, 0});
    up_cell.setVisible(1);
    down_cell.setVisible(1);
    right_cell.setVisible(1);
    left_cell.setVisible(1);
    field.getCell(current_coords + Vector{-1, -1}).setVisible(1);
    field.getCell(current_coords + Vector{-1, 1}).setVisible(1);
    field.getCell(current_coords + Vector{1, -1}).setVisible(1);
    field.getCell(current_coords + Vector{1, 1}).setVisible(1);
    if(up_cell.isCross_active()) fillLight(field, current_coords + Vector{0, 1}, distance - 1);
    if(down_cell.isCross_active()) fillLight(field, current_coords + Vector{0, -1}, distance - 1);
    if(right_cell.isCross_active()) fillLight(field, current_coords + Vector{1, 0}, distance - 1);
    if(left_cell.isCross_active())fillLight(field, current_coords + Vector{-1, 0}, distance - 1);
    return;
}


void LightController::setLight(Field& field, Vector player_coords, int distance){
    removeLight(field, player_coords, distance);
    fillLight(field, player_coords, distance);
}





void LightController::removeLight(Field& field, Vector player_coords, int distance){
    for(int i = std::max(0, player_coords.y - distance * 2); i < std::min(player_coords.y + distance * 2 + 1, field.size().y); i++){
        for(int j = std::max(0, player_coords.x - distance * 2); j < std::min(player_coords.x + distance * 2 + 1, field.size().x); j++){
            field.getCell(Vector(j, i)).setVisible(0);
        }
    }  
}