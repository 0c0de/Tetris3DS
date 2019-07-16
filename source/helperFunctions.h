#include <stdlib.h>
#include <stdio.h>
#include <string>
#include <vector>


//Game size will be 90 by 190 but in will be 18 by 38 in real format for 3DS
std::vector<std::vector<int>> gameTable(9, std::vector<int>(19));

//Array for store the blocks
std::vector<std::vector<int>> block(4, std::vector<int>(2));

bool isInsideBorder(int x, int y){
    return ( x > 0 && x <= 9 && y <= 17 );
}

bool canMove(){
    for(int x = 0; x < 4; x++){
        int xPos = block[x][0];
        int yPos = block[x][1];

        int gameX = (xPos/10)-14;
        int gameY = (yPos/10)-3;

        if(!isInsideBorder(gameX, gameY)){
            return false;
        }

        if(gameTable[gameX][gameY] != 0){
            return false;
        }
    }
    return true;
}

void setBlockPosition(int gameX, int gameY){
    gameX = (gameX/10)-14;
    gameY = (gameY/10)-3;
    gameTable[gameX][gameY] = 1;
}

void InitGameTable(){
    for(int y = 0; y < 19; y++){
        for(int x = 0; x < 9; x++){
            gameTable[x][y] = 0;
        }
    }
}

void initGame(){
    InitGameTable();
}

void clearRow(int y){
    y = (y/10)-3;
    for(int x = 0; x < 9; x++ ){
        gameTable[x][y] = 0;
    }
    
}