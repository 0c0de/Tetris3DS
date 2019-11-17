#include <stdlib.h>
#include <stdio.h>
#include <string>
#include <vector>


//Game size will be 90 by 190 but in will be 18 by 38 in real format for 3DS
std::vector<std::vector<int>> gameTable(9, std::vector<int>(19));

//Array for store the blocks
std::vector<std::vector<int>> block(4, std::vector<int>(2));

//Simple function to check if the blocks are inside the borders of the game table
bool isInsideBorder(int x, int y, std::string dir = ""){
    if(dir == "LEFT"){
        return (x > 1 && y < 17);
    }else if(dir == "RIGHT"){
        return (x < 8 && y < 17);
    }else if(dir == "ROTATING"){
        return(x < 8 || x > 0);
    }else{
        return (y < 17 );
    }
}

//Check if the block can move, by checking the block position
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

//Translates the block position into the matrix gametable space and set the state to 0,1 or 2
void setBlockPosition(int gameX, int gameY, int valueToSet){
    gameX = (gameX/10)-14;
    gameY = (gameY/10);
    gameTable[gameX][gameY] = valueToSet;
}

//Set the game table to 0, so all is empty
void InitGameTable(){
    for(int y = 0; y < 17; y++){
        for(int x = 0; x < 9; x++){
            gameTable[x][y] = 0;
        }
    }
}

//Draw the boxes when has a state of 1, with a gameworld size
void drawGameTable(){
    for(int y = 0; y < 17; y++){
        for (int x = 0; x < 9; x++){
            if(gameTable[x][y] == 1){
                int convertedX = ((x+1) * 10) + 130;
                int convertedY = ((y+1) * 10);
                C2D_DrawRectSolid(convertedX, convertedY, 1, 10,10, C2D_Color32(66, 245, 114, 255));
            }
        }
    }
}

//Initialises the game
void initGame(){
    InitGameTable();
}

bool isFull(int y){
    for (int x = 1; x < 9; x++){
        if(gameTable[x][y] == 0){
            return false;
        }
    }
    return true;
}

//Make a score, then this is executed, just clean the row that is completed
void clearRow(int y){
    for(int x = 0; x < 9; x++ ){
        gameTable[x][y] = 0;
    }   
}

//Decrease the next row when a row is completed
void decreaseRow(int y){
    for(int column = y; column <= 0; column--){
        printf("\nCopying column %i to column %i", column - 1, column);
        for(int row = 1; row < 9; row++){
            printf("%i --> %i", gameTable[row][column], gameTable[row][column-1]);
            gameTable[row][column] = gameTable[row][column-1];
        }
    }
}

void checkBoard(){
    for(int y = 0; y < 17; y++){
        if(isFull(y)){
            clearRow(y);
            decreaseRow(y);
            y--;
        }
    }
}

//Set state of the block to 1, so they are static
void lockBlock(){
    for(int x = 0; x < 4; x++){
        int xPos = block[x][0];
        int yPos = block[x][1] - 1;
        setBlockPosition(xPos, yPos, 1);
    }
}

//Updates the game table matrix
void UpdateGameTable(){
	for(int x = 0; x < 9; x++){
        for(int y = 0; y < 17; y++){
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