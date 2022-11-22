
#include <iostream>
#include "zell.h"
#include <unistd.h>

u_int64_t iteration = 0;

void printWorld(Zell** world){

    system("clear");
    std::cout << "Iteration: "<< iteration << std::endl;
    for(u_int64_t i = 0; i < global::cols; i++){
        for(u_int64_t j = 0; j < global::rows; j++){
            Zell* z = &world[i][j];
            if(z->isAlive()){
                std::cout << "x";
            }else{
                std::cout << " ";
            }
            
        }
        std::cout << std::endl;
    }  
    iteration++;
}

void gameloop(Zell** world){

    while(true){
        for(u_int64_t i = 0; i < global::cols; i++){
            for(u_int64_t j = 0; j < global::rows; j++){
                Zell* z = &world[i][j];
                z->update(world);
            }
        }
        printWorld(world);
        for(u_int64_t i = 0; i < global::cols; i++){
            for(u_int64_t j = 0; j < global::rows; j++){
                Zell* z = &world[i][j];
                z->updateIteration();
            }
        }
        sleep(1);
    }
}

int main(){

    Zell** world = new Zell* [global::cols];
    for(int i = 0; i < global::cols; ++i)
        world[i] = new Zell [global::rows];

    for(u_int64_t i = 0; i < global::cols; i++){
        for(u_int64_t j = 0; j < global::rows; j++){
            world[i][j].setPosition(i,j);
        }
    }

    gameloop(world);
}

