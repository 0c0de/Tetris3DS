#include <stdlib.h>
#include <stdio.h>
#include <string>
#include <vector>


//Game size will be 90 by 190 but in will be 18 by 38 in real format for 3DS
std::vector<std::vector<int>> gameTable(9, std::vector<int>(19));

//Array for store the blocks
std::vector<std::vector<int>> block(4, std::vector<int>(2));

bool isInsideBorder(int x, int y, std::string dir = ""){
    if(dir == "LEFT"){
        return (x > 1 && y < 17);
    }else if(dir == "RIGHT"){
        return (x < 8 && y < 17);
    }else{
        return (y < 17 );
    }
}

bool canMove(std::string direction = ""){
    for(int x = 0; x < 4; x++){
        int xPos = block[x][0];
        int yPos = block[x][1];

        int gameX = (xPos/10)-14;
        int gameY = (yPos/10);

        if(!isInsideBorder(gameX, gameY, direction)){
            return false;
        }

        if(gameTable[gameX][gameY] == 1){
            return false;
        }
    }
    return true;
}

void setBlockPosition(int gameX, int gameY, int valueToSet){
    gameX = (gameX/10)-14;
    gameY = (gameY/10);
    gameTable[gameX][gameY] = valueToSet;
}

void InitGameTable(){
    for(int y = 0; y < 17; y++){
        for(int x = 0; x < 9; x++){
            gameTable[x][y] = 0;
        }
    }
}

void lockBlock(){
    for(int x = 0; x < 4; x++){
        int xPos = block[x][0];
        int yPos = block[x][1] - 1;
        setBlockPosition(xPos, yPos, 1);
    }
}

void drawGameTable(){
    for(int y = 0; y < 17; y++){
        for (int x = 0; x < 9; x++){
            if(gameTable[x][y] == 1){
                int convertedX = ((x+1) * 10) + 130;
                int convertedY = ((y+1) * 10);
                //printf("Converted positions X: %i, Y: %i", convertedX, convertedY);
                C2D_DrawRectSolid(convertedX, convertedY, 1, 10,10, C2D_Color32(66, 245, 114, 255));
            }
        }
    }
}

void initGame(){
    InitGameTable();
}

void clearRow(int y){
    y = (y/10);
    for(int x = 0; x < 9; x++ ){
        gameTable[x][y] = 0;
    }
    
}

void UpdateGameTable(){
	for(int y = 0; y < 17; y++){
		for(int x = 0; x < 9; x++){
			if(gameTable[x][y] == 2){
				gameTable[x][y] = 0;
			}
		}
	}
	for(int x = 0; x < 4; x++){
		int blockXPosition = block[x][0];
		int blockYPosition = block[x][1];
		setBlockPosition(blockXPosition, blockYPosition, 2);
	}
}