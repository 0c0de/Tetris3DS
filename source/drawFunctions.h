#include <citro2d.h>
#include <vector>
#include <stdlib.h>
#include <stdio.h>
#include <string>
#include <math.h>
#include "helperFunctions.h"
#include <vector>

//Color to fill the entire screen when updates graphics
u32 clrColor = C2D_Color32(0,0,0,255);

//Boolean to detect which figure is spawned
bool isL,isO,isZ,isI,isT, isLInverted, isZInverted = false;

//Will keep track of the rotations of the blocks
int rotateIndex = 1;

//Init all citro2d and citro3d stuff
void InitAllStuff(){
    C2D_Init(C2D_DEFAULT_MAX_OBJECTS);
    C3D_Init(C3D_DEFAULT_CMDBUF_SIZE);
    C2D_Prepare();
}

//Clear all citros related things
void DeInitAll(){
    C2D_Fini();
    C3D_Fini();
}

//Draw the game board
void DrawBoard(){
    C2D_DrawRectangle(145, 0, 0, 90, 185, C2D_Color32(66, 245, 114, 255), C2D_Color32(66, 245, 114, 255), C2D_Color32(66, 245, 114, 255), C2D_Color32(66, 245, 114, 255));
    C2D_DrawRectangle(150, 0, 0, 80, 180, C2D_Color32(0,0,0,255), C2D_Color32(0,0,0,255), C2D_Color32(0,0,0,255), C2D_Color32(0,0,0,255));
}

void DrawT(int x, int y, int blockPose){
    isL = false;
    isO = false;
    isZ = false;
    isI = false;
    isT = true;
    isZInverted = false;
    isLInverted = false;
    if(blockPose == 1){
        C2D_DrawRectSolid(x, y, 1, 10,10, C2D_Color32(66, 245, 114, 255));
        block[0][0] = x;
        block[0][1] = y;
        C2D_DrawRectSolid(x, y-10, 1, 10,10, C2D_Color32(66, 245, 114, 255));
        block[1][0] = x;
        block[1][1] = y-10;
        C2D_DrawRectSolid(x+10, y, 1, 10,10, C2D_Color32(66, 245, 114, 255));
        block[2][0] = x+10;
        block[2][1] = y;
        C2D_DrawRectSolid(x-10, y, 1, 10,10, C2D_Color32(66, 245, 114, 255));
        block[3][0] = x-10;
        block[3][1] = y;
    }else if (blockPose == 2){
        C2D_DrawRectSolid(x, y, 1, 10,10, C2D_Color32(66, 245, 114, 255));
        block[0][0] = x;
        block[0][1] = y;
        C2D_DrawRectSolid(x, y+10, 1, 10,10, C2D_Color32(66, 245, 114, 255));
        block[1][0] = x;
        block[1][1] = y+10;
        C2D_DrawRectSolid(x, y-10, 1, 10,10, C2D_Color32(66, 245, 114, 255));
        block[2][0] = x;
        block[2][1] = y-10;
        C2D_DrawRectSolid(x+10, y, 1, 10,10, C2D_Color32(66, 245, 114, 255));
        block[3][0] = x+10;
        block[3][1] = y; 
    }else if(blockPose == 3){
        C2D_DrawRectSolid(x, y, 1, 10,10, C2D_Color32(66, 245, 114, 255));
        block[0][0] = x;
        block[0][1] = y;
        C2D_DrawRectSolid(x-10, y, 1, 10,10, C2D_Color32(66, 245, 114, 255));
        block[1][0] = x-10;
        block[1][1] = y;
        C2D_DrawRectSolid(x, y+10, 1, 10,10, C2D_Color32(66, 245, 114, 255));
        block[2][0] = x;
        block[2][1] = y+10;
        C2D_DrawRectSolid(x+10, y, 1, 10,10, C2D_Color32(66, 245, 114, 255));
        block[3][0] = x+10;
        block[3][1] = y;
    }else if(blockPose == 4){
        C2D_DrawRectSolid(x, y, 1, 10,10, C2D_Color32(66, 245, 114, 255));
        block[0][0] = x;
        block[0][1] = y;
        C2D_DrawRectSolid(x, y-10, 1, 10,10, C2D_Color32(66, 245, 114, 255));
        block[1][0] = x;
        block[1][1] = y-10;
        C2D_DrawRectSolid(x, y+10, 1, 10,10, C2D_Color32(66, 245, 114, 255));
        block[2][0] = x;
        block[2][1] = y+10;
        C2D_DrawRectSolid(x-10, y, 1, 10,10, C2D_Color32(66, 245, 114, 255));
        block[3][0] = x-10;
        block[3][1] = y;
    }else{
        rotateIndex = 1;
    }
}

void DrawL(int x, int y, int blockPose){
    isL = true;
    isO = false;
    isZ = false;
    isI = false;
    isT = false;
    isZInverted = false;
    isLInverted = false;
    if(blockPose == 1){
        C2D_DrawRectSolid(x, y, 1, 10,10, C2D_Color32(66, 245, 114, 255));
        block[0][0] = x;
        block[0][1] = y;
        C2D_DrawRectSolid(x, y-10, 1, 10,10, C2D_Color32(66, 245, 114, 255));
        block[1][0] = x;
        block[1][1] = y-10;
        C2D_DrawRectSolid(x, y-20, 1, 10,10, C2D_Color32(66, 245, 114, 255));
        block[2][0] = x;
        block[2][1] = y-20;
        C2D_DrawRectSolid(x+10, y, 1, 10,10, C2D_Color32(66, 245, 114, 255));
        block[3][0] = x+10;
        block[3][1] = y;
    }else if (blockPose == 2){
        C2D_DrawRectSolid(x, y, 1, 10,10, C2D_Color32(66, 245, 114, 255));
        block[0][0] = x;
        block[0][1] = y;
        C2D_DrawRectSolid(x, y+10, 1, 10,10, C2D_Color32(66, 245, 114, 255));
        block[1][0] = x;
        block[1][1] = y+10;
        C2D_DrawRectSolid(x+10, y, 1, 10,10, C2D_Color32(66, 245, 114, 255));
        block[2][0] = x+10;
        block[2][1] = y;
        C2D_DrawRectSolid(x+20, y, 1, 10,10, C2D_Color32(66, 245, 114, 255));
        block[3][0] = x+20;
        block[3][1] = y; 
    }else if(blockPose == 3){
        C2D_DrawRectSolid(x, y, 1, 10,10, C2D_Color32(66, 245, 114, 255));
        block[0][0] = x;
        block[0][1] = y;
        C2D_DrawRectSolid(x-10, y, 1, 10,10, C2D_Color32(66, 245, 114, 255));
        block[1][0] = x-10;
        block[1][1] = y;
        C2D_DrawRectSolid(x, y+10, 1, 10,10, C2D_Color32(66, 245, 114, 255));
        block[2][0] = x;
        block[2][1] = y+10;
        C2D_DrawRectSolid(x, y+20, 1, 10,10, C2D_Color32(66, 245, 114, 255));
        block[3][0] = x;
        block[3][1] = y+20;
    }else if(blockPose == 4){
        C2D_DrawRectSolid(x, y, 1, 10,10, C2D_Color32(66, 245, 114, 255));
        block[0][0] = x;
        block[0][1] = y;
        C2D_DrawRectSolid(x-10, y, 1, 10,10, C2D_Color32(66, 245, 114, 255));
        block[1][0] = x-10;
        block[1][1] = y;
        C2D_DrawRectSolid(x-20, y, 1, 10,10, C2D_Color32(66, 245, 114, 255));
        block[2][0] = x-20;
        block[2][1] = y;
        C2D_DrawRectSolid(x, y-10, 1, 10,10, C2D_Color32(66, 245, 114, 255));
        block[3][0] = x;
        block[3][1] = y-10;
    }else{
        rotateIndex = 1;
    }
}

void DrawLInverted(int x, int y, int blockPose){
    isL = true;
    isO = false;
    isZ = false;
    isI = false;
    isT = false;
    isZInverted = false;
    isLInverted = true;
    if(blockPose == 1){
        C2D_DrawRectSolid(x, y, 1, 10,10, C2D_Color32(66, 245, 114, 255));
        block[0][0] = x;
        block[0][1] = y;
        C2D_DrawRectSolid(x, y+10, 1, 10,10, C2D_Color32(66, 245, 114, 255));
        block[1][0] = x;
        block[1][1] = y+10;
        C2D_DrawRectSolid(x, y+20, 1, 10,10, C2D_Color32(66, 245, 114, 255));
        block[2][0] = x;
        block[2][1] = y+20;
        C2D_DrawRectSolid(x-10, y, 1, 10,10, C2D_Color32(66, 245, 114, 255));
        block[3][0] = x-10;
        block[3][1] = y;
    }else if (blockPose == 2){
        C2D_DrawRectSolid(x, y, 1, 10,10, C2D_Color32(66, 245, 114, 255));
        block[0][0] = x;
        block[0][1] = y;
        C2D_DrawRectSolid(x, y-10, 1, 10,10, C2D_Color32(66, 245, 114, 255));
        block[1][0] = x;
        block[1][1] = y-10;
        C2D_DrawRectSolid(x-10, y, 1, 10,10, C2D_Color32(66, 245, 114, 255));
        block[2][0] = x-10;
        block[2][1] = y;
        C2D_DrawRectSolid(x-20, y, 1, 10,10, C2D_Color32(66, 245, 114, 255));
        block[3][0] = x-20;
        block[3][1] = y; 
    }else if(blockPose == 3){
        C2D_DrawRectSolid(x, y, 1, 10,10, C2D_Color32(66, 245, 114, 255));
        block[0][0] = x;
        block[0][1] = y;
        C2D_DrawRectSolid(x+10, y, 1, 10,10, C2D_Color32(66, 245, 114, 255));
        block[1][0] = x+10;
        block[1][1] = y;
        C2D_DrawRectSolid(x, y-10, 1, 10,10, C2D_Color32(66, 245, 114, 255));
        block[2][0] = x;
        block[2][1] = y-10;
        C2D_DrawRectSolid(x, y-20, 1, 10,10, C2D_Color32(66, 245, 114, 255));
        block[3][0] = x;
        block[3][1] = y-20;
    }else if(blockPose == 4){
        C2D_DrawRectSolid(x, y, 1, 10,10, C2D_Color32(66, 245, 114, 255));
        block[0][0] = x;
        block[0][1] = y;
        C2D_DrawRectSolid(x+10, y, 1, 10,10, C2D_Color32(66, 245, 114, 255));
        block[1][0] = x+10;
        block[1][1] = y;
        C2D_DrawRectSolid(x+20, y, 1, 10,10, C2D_Color32(66, 245, 114, 255));
        block[2][0] = x+20;
        block[2][1] = y;
        C2D_DrawRectSolid(x, y+10, 1, 10,10, C2D_Color32(66, 245, 114, 255));
        block[3][0] = x;
        block[3][1] = y+10;
    }else{
        rotateIndex = 1;
    }
}

void DrawO(int x, int y, int blockPose){
    isL = false;
    isO = true;
    isZ = false;
    isI = false;
    isT = false;
    isZInverted = false;
    isLInverted = false;
    C2D_DrawRectSolid(x, y, 1, 10,10, C2D_Color32(66, 245, 114, 255));
    block[0][0] = x;
    block[0][1] = y;
    C2D_DrawRectSolid(x+10, y, 1, 10,10, C2D_Color32(66, 245, 114, 255));
    block[1][0] = x+10;
    block[1][1] = y;
    C2D_DrawRectSolid(x, y-10, 1, 10,10, C2D_Color32(66, 245, 114, 255));
    block[2][0] = x;
    block[2][1] = y-10;
    C2D_DrawRectSolid(x+10, y-10, 1, 10,10, C2D_Color32(66, 245, 114, 255));
    block[3][0] = x+10;
    block[3][1] = y-10;
}

void DrawZ(int x, int y, int blockPose){
    isL = false;
    isO = false;
    isZ = true;
    isI = false;
    isT = false;
    isZInverted = false;
    isLInverted = false;
    if(blockPose == 1){
        C2D_DrawRectSolid(x, y, 1, 10,10, C2D_Color32(66, 245, 114, 255));
        block[0][0] = x;
        block[0][1] = y;
        C2D_DrawRectSolid(x+10, y, 1, 10,10, C2D_Color32(66, 245, 114, 255));
        block[1][0] = x+10;
        block[1][1] = y;
        C2D_DrawRectSolid(x+10, y-10, 1, 10,10, C2D_Color32(66, 245, 114, 255));
        block[2][0] = x+10;
        block[2][1] = y-10;
        C2D_DrawRectSolid(x+20, y-10, 1, 10,10, C2D_Color32(66, 245, 114, 255));
        block[3][0] = x+20;
        block[3][1] = y-10;
    }
    if(blockPose == 2){
        C2D_DrawRectSolid(x, y, 1, 10,10, C2D_Color32(66, 245, 114, 255));
        block[0][0] = x;
        block[0][1] = y;
        C2D_DrawRectSolid(x+10, y, 1, 10,10, C2D_Color32(66, 245, 114, 255));
        block[1][0] = x+10;
        block[1][1] = y;
        C2D_DrawRectSolid(x, y-10, 1, 10,10, C2D_Color32(66, 245, 114, 255));
        block[2][0] = x;
        block[2][1] = y-10;
        C2D_DrawRectSolid(x+10, y+10, 1, 10,10, C2D_Color32(66, 245, 114, 255));
        block[3][0] = x+10;
        block[3][1] = y+10;
    }
    if (blockPose == 3){
        C2D_DrawRectSolid(x, y, 1, 10,10, C2D_Color32(66, 245, 114, 255));
        block[0][0] = x;
        block[0][1] = y;
        C2D_DrawRectSolid(x+10, y, 1, 10,10, C2D_Color32(66, 245, 114, 255));
        block[1][0] = x+10;
        block[1][1] = y;
        C2D_DrawRectSolid(x+10, y-10, 1, 10,10, C2D_Color32(66, 245, 114, 255));
        block[2][0] = x+10;
        block[2][1] = y-10;
        C2D_DrawRectSolid(x+20, y-10, 1, 10,10, C2D_Color32(66, 245, 114, 255));
        block[3][0] = x+20;
        block[3][1] = y-10;
    }
    if (blockPose == 4){
        C2D_DrawRectSolid(x, y, 1, 10,10, C2D_Color32(66, 245, 114, 255));
        block[0][0] = x;
        block[0][1] = y;
        C2D_DrawRectSolid(x+10, y, 1, 10,10, C2D_Color32(66, 245, 114, 255));
        block[1][0] = x+10;
        block[1][1] = y;
        C2D_DrawRectSolid(x, y-10, 1, 10,10, C2D_Color32(66, 245, 114, 255));
        block[2][0] = x;
        block[2][1] = y-10;
        C2D_DrawRectSolid(x+10, y+10, 1, 10,10, C2D_Color32(66, 245, 114, 255));
        block[3][0] = x+10;
        block[3][1] = y+10;
    }

    if(blockPose >= 5){
        rotateIndex = 1;
    }
}

void DrawZInverted(int x, int y, int blockPose){
    isL = false;
    isO = false;
    isZ = false;
    isI = false;
    isT = false;
    isZInverted = true;
    isLInverted = false;
    if(blockPose == 1){
        C2D_DrawRectSolid(x, y, 1, 10,10, C2D_Color32(66, 245, 114, 255));
        block[0][0] = x;
        block[0][1] = y;
        C2D_DrawRectSolid(x-10, y, 1, 10,10, C2D_Color32(66, 245, 114, 255));
        block[1][0] = x-10;
        block[1][1] = y;
        C2D_DrawRectSolid(x-10, y+10, 1, 10,10, C2D_Color32(66, 245, 114, 255));
        block[2][0] = x-10;
        block[2][1] = y+10;
        C2D_DrawRectSolid(x-20, y+10, 1, 10,10, C2D_Color32(66, 245, 114, 255));
        block[3][0] = x-20;
        block[3][1] = y+10;
    }
    if(blockPose == 2){
        C2D_DrawRectSolid(x, y, 1, 10,10, C2D_Color32(66, 245, 114, 255));
        block[0][0] = x;
        block[0][1] = y;
        C2D_DrawRectSolid(x-10, y, 1, 10,10, C2D_Color32(66, 245, 114, 255));
        block[1][0] = x-10;
        block[1][1] = y;
        C2D_DrawRectSolid(x, y+10, 1, 10,10, C2D_Color32(66, 245, 114, 255));
        block[2][0] = x;
        block[2][1] = y+10;
        C2D_DrawRectSolid(x-10, y-10, 1, 10,10, C2D_Color32(66, 245, 114, 255));
        block[3][0] = x-10;
        block[3][1] = y-10;
    }
    if (blockPose == 3){
        C2D_DrawRectSolid(x, y, 1, 10,10, C2D_Color32(66, 245, 114, 255));
        block[0][0] = x;
        block[0][1] = y;
        C2D_DrawRectSolid(x-10, y, 1, 10,10, C2D_Color32(66, 245, 114, 255));
        block[1][0] = x-10;
        block[1][1] = y;
        C2D_DrawRectSolid(x-10, y+10, 1, 10,10, C2D_Color32(66, 245, 114, 255));
        block[2][0] = x-10;
        block[2][1] = y+10;
        C2D_DrawRectSolid(x-20, y+10, 1, 10,10, C2D_Color32(66, 245, 114, 255));
        block[3][0] = x-20;
        block[3][1] = y+10;
    }
    if (blockPose == 4){
        C2D_DrawRectSolid(x, y, 1, 10,10, C2D_Color32(66, 245, 114, 255));
        block[0][0] = x;
        block[0][1] = y;
        C2D_DrawRectSolid(x-10, y, 1, 10,10, C2D_Color32(66, 245, 114, 255));
        block[1][0] = x-10;
        block[1][1] = y;
        C2D_DrawRectSolid(x, y+10, 1, 10,10, C2D_Color32(66, 245, 114, 255));
        block[2][0] = x;
        block[2][1] = y+10;
        C2D_DrawRectSolid(x-10, y-10, 1, 10,10, C2D_Color32(66, 245, 114, 255));
        block[3][0] = x-10;
        block[3][1] = y-10;
    }

    if(blockPose >= 5){
        rotateIndex = 1;
    }
}

void DrawI(int x, int y, int blockPose){
    isL = false;
    isO = false;
    isZ = false;
    isI = true;
    isT = false;
    isZInverted = false;
    isLInverted = false;
    if(blockPose == 1){
        C2D_DrawRectSolid(x, y, 1, 10,10, C2D_Color32(66, 245, 114, 255));
        block[0][0] = x;
        block[0][1] = y;
        C2D_DrawRectSolid(x, y-10, 1, 10,10, C2D_Color32(66, 245, 114, 255));
        block[1][0] = x;
        block[1][1] = y-10;
        C2D_DrawRectSolid(x, y+10, 1, 10,10, C2D_Color32(66, 245, 114, 255));
        block[2][0] = x;
        block[2][1] = y+10;
        C2D_DrawRectSolid(x, y+20, 1, 10,10, C2D_Color32(66, 245, 114, 255));
        block[3][0] = x;
        block[3][1] = y+20;
    }else if (blockPose == 2){
        C2D_DrawRectSolid(x, y, 1, 10,10, C2D_Color32(66, 245, 114, 255));
        block[0][0] = x;
        block[0][1] = y;
        C2D_DrawRectSolid(x+10, y, 1, 10,10, C2D_Color32(66, 245, 114, 255));
        block[1][0] = x+10;
        block[1][1] = y;
        C2D_DrawRectSolid(x-10, y, 1, 10,10, C2D_Color32(66, 245, 114, 255));
        block[2][0] = x-10;
        block[2][1] = y;
        C2D_DrawRectSolid(x-20, y, 1, 10,10, C2D_Color32(66, 245, 114, 255));
        block[3][0] = x-20;
        block[3][1] = y;
    }else if (blockPose == 3){
        C2D_DrawRectSolid(x, y, 1, 10,10, C2D_Color32(66, 245, 114, 255));
        block[0][0] = x;
        block[0][1] = y;
        C2D_DrawRectSolid(x, y-10, 1, 10,10, C2D_Color32(66, 245, 114, 255));
        block[1][0] = x;
        block[1][1] = y-10;
        C2D_DrawRectSolid(x, y+10, 1, 10,10, C2D_Color32(66, 245, 114, 255));
        block[2][0] = x;
        block[2][1] = y+10;
        C2D_DrawRectSolid(x, y+20, 1, 10,10, C2D_Color32(66, 245, 114, 255));
        block[3][0] = x;
        block[3][1] = y+20;
    }else if (blockPose == 4){
        C2D_DrawRectSolid(x, y, 1, 10,10, C2D_Color32(66, 245, 114, 255));
        block[0][0] = x;
        block[0][1] = y;
        C2D_DrawRectSolid(x+10, y, 1, 10,10, C2D_Color32(66, 245, 114, 255));
        block[1][0] = x+10;
        block[1][1] = y;
        C2D_DrawRectSolid(x-10, y, 1, 10,10, C2D_Color32(66, 245, 114, 255));
        block[2][0] = x-10;
        block[2][1] = y;
        C2D_DrawRectSolid(x-20, y, 1, 10,10, C2D_Color32(66, 245, 114, 255));
        block[3][0] = x-20;
        block[3][1] = y;
    }

    if(blockPose >= 5){
        rotateIndex = 1;
    }
}

/*void rotateBlocks(int x, int y){
    if(rotateIndex > 4){
        rotateIndex = 1;
    }
}*/

void nextPiece(int x, int y){
    rotateIndex = 1;
    int numberGenerated = rand() % 7 + 1;
	printf("Random number generated is: %i", numberGenerated);

    if(numberGenerated == 1){
        DrawL(x,y, rotateIndex);
    }else if (numberGenerated == 2){
        DrawO(x,y,rotateIndex);
    }else if(numberGenerated == 3){
        DrawI(x,y, rotateIndex);
    }else if(numberGenerated == 4){
        DrawZ(x,y,rotateIndex);
    }else if(numberGenerated == 5){
        DrawT(x,y,rotateIndex);
    }else if(numberGenerated == 6){
        DrawZInverted(x,y,rotateIndex);
    }else if(numberGenerated == 7){
        DrawLInverted(x,y, rotateIndex);
    }
}

void drawSelectedPiece(int x, int y){
    if(isL){
        DrawL(x,y, rotateIndex);
    }else if (isO){
        DrawO(x,y,rotateIndex);
    }else if(isI){
        DrawI(x,y, rotateIndex);
    }else if(isZ){
        DrawZ(x,y,rotateIndex);
    }else if(isT){
        DrawT(x,y, rotateIndex);
    }else if(isLInverted){
        DrawLInverted(x,y, rotateIndex);
    }else if(isZInverted){
        DrawZInverted(x,y,rotateIndex);
    }
}