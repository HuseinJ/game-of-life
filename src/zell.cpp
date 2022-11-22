#include "zell.h"
#include <iostream>

bool Zell::isAlive(){
    return alive;
}

void Zell::update(Zell** world){

    u_int8_t aliveNeighbours = countNeighbours(world);

    if(alive){
        if(aliveNeighbours == 2 || aliveNeighbours == 3){
            this->futureAliveState = true;
        }else{
            futureAliveState = false;
        }
    }else{
        if(aliveNeighbours == 3){
            this->futureAliveState = true;
        }
    }
    return;
}

u_int64_t Zell::countNeighbours(Zell** world){
    u_int8_t aliveNeighbours = 0;

    for (int i = -1; i <= 1; i++){   
        for (int j = -1; j <= 1; j++){
            if (!(i == 0 && j == 0) && inBounds(posRow + i, posCol + j) && world[posCol+j][posRow+i].alive){
                aliveNeighbours++;
            }
        }
    }

    return aliveNeighbours;
}

bool Zell::inBounds(int row, int col){
    return ((row >= 0 && row < global::rows - 2) && (col >= 0 && col < global::cols - 2));
}

void Zell::updateIteration(){
    this->alive = this->futureAliveState;
}

void Zell::setPosition(size_t posCol, size_t posRow){
    this->posCol = posCol;
    this->posRow = posRow;
}

