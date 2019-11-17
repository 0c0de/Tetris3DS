#include <citro2d.h>
#include <3ds.h>
#include "drawFunctions.h"
#include <ctime>
#include <thread>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#define SCREEN_WIDTH  400
#define SCREEN_HEIGHT 240

int speedX = 0;
int speedY = -1;

int defaultXPos = 200;
int defaultYPos = 30;

int XPos = defaultXPos;
int YPos = defaultYPos;

u64 actualTime = 0;

std::string direction;

void printMatrixStatus(){
	//Print matrix info		
	for(int y = 0; y < 17; y++){
		for(int x = 0; x < 9; x++){
			printf("\x1b[%i;%iH%i ",y,x, gameTable[x][y]);
		}
		printf("\n");
	}
}

//---------------------------------------------------------------------------------
int main(int argc, char* argv[]) {
//---------------------------------------------------------------------------------
	// Init libs
	gfxInitDefault();
	InitAllStuff();
	consoleInit(GFX_BOTTOM, NULL);

	srand(time(0));
	
	// Create screens
	C3D_RenderTarget* top = C2D_CreateScreenTarget(GFX_TOP, GFX_LEFT);
	C3D_RenderTarget* bottom = C2D_CreateScreenTarget(GFX_BOTTOM, GFX_LEFT);

	//Init timer
	actualTime = osGetTime() + 800;

	initGame();

	nextPiece(defaultXPos, defaultYPos);
	// Main loop
	while (aptMainLoop())
	{
		hidScanInput();
		// Respond to user input
		u32 kDown = hidKeysDown();
		if (kDown & KEY_START){
			break; // break in order to return to hbmenu

		}else if (kDown & KEY_DLEFT){
			XPos -= 10;
			direction = "LEFT";
			if(!canMove(direction)){
				XPos += 10;
			}else{
				UpdateGameTable();
			}
		
		}else if(kDown & KEY_DRIGHT){
			XPos += 10;
			direction = "RIGHT";
			if(!canMove(direction)){
				XPos -= 10;
			}else{
				UpdateGameTable();
			}
			
		}else if (kDown & KEY_DUP){
			direction = "ROTATING";
			rotateIndex++;
			if(!canMove(direction)){
				rotateIndex--;
			}else{
				UpdateGameTable();
			}
			
		}else{
			direction = "";
		}


		//printf("\x1b[10;15HTetris Game");
		//printf("\x1b[11;20HScore");

		// Render the scene
		C3D_FrameBegin(C3D_FRAME_SYNCDRAW);
		C2D_TargetClear(top, clrColor);
		C2D_SceneBegin(top);

		DrawBoard();
		drawGameTable();

		drawSelectedPiece(XPos, YPos);
		//Game Loop
		if(osGetTime() > actualTime){
			drawGameTable();
			if(canMove()){
				YPos+=10;
				UpdateGameTable();
			}

			if(!canMove()){
				lockBlock();
				checkBoard();
				XPos = defaultXPos;
				YPos = defaultYPos;
				nextPiece(XPos, YPos);
			}
			
			printMatrixStatus();
			actualTime = osGetTime() + 500;
		}else{
			if(canMove()){
				drawSelectedPiece(XPos, YPos);
			}
		}

		C3D_FrameEnd(0);
	}

	// Deinit libs
	DeInitAll();
	gfxExit();
	return 0;
}