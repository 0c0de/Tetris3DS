#include <citro2d.h>
#include <vector>
#include <stdlib.h>
#include <stdio.h>
#include <string>
#include "helperFunctions.h"
#include <vector>

//Color to fill the entire screen when updates graphics
u32 clrColor = C2D_Color32(0,0,0,255);

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
    C2D_DrawRectangle(140, 20, 0, 100, 200, C2D_Color32(66, 245, 114, 255), C2D_Color32(66, 245, 114, 255), C2D_Color32(66, 245, 114, 255), C2D_Color32(66, 245, 114, 255));
    C2D_DrawRectangle(142, 25, 0, 95, 190, C2D_Color32(0,0,0,255), C2D_Color32(0,0,0,255), C2D_Color32(0,0,0,255), C2D_Color32(0,0,0,255));
}

//Draw th L figure and update Game Board
void DrawL(int x, int y){
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
}

void DrawO(int x, int y){
    C2D_DrawRectSolid(x, y, 1, 10,10, C2D_Color32(66, 245, 114, 255));
    C2D_DrawRectSolid(x-10, y, 1, 10,10, C2D_Color32(66, 245, 114, 255));
    C2D_DrawRectSolid(x, y-10, 1, 10,10, C2D_Color32(66, 245, 114, 255));
    C2D_DrawRectSolid(x-10, y-10, 1, 10,10, C2D_Color32(66, 245, 114, 255));
}

void DrawZ(int x, int y){
    C2D_DrawRectSolid(x, y, 1, 10,10, C2D_Color32(66, 245, 114, 255));
    C2D_DrawRectSolid(x-10, y, 1, 10,10, C2D_Color32(66, 245, 114, 255));
    C2D_DrawRectSolid(x-10, y-10, 1, 10,10, C2D_Color32(66, 245, 114, 255));
    C2D_DrawRectSolid(x-20, y-10, 1, 10,10, C2D_Color32(66, 245, 114, 255));
}

void DrawT(int x, int y){
    C2D_DrawRectSolid(x, y, 1, 10,10, C2D_Color32(66, 245, 114, 255));
    C2D_DrawRectSolid(x, y-10, 1, 10,10, C2D_Color32(66, 245, 114, 255));
    C2D_DrawRectSolid(x-10, y-10, 1, 10,10, C2D_Color32(66, 245, 114, 255));
    C2D_DrawRectSolid(x+20, y-10, 1, 10,10, C2D_Color32(66, 245, 114, 255));
}