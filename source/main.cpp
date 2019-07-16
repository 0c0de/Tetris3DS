// Simple citro2d untextured shape example
#include <citro2d.h>
#include <3ds.h>
#include "drawFunctions.h"

#include <thread>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#define SCREEN_WIDTH  400
#define SCREEN_HEIGHT 240

int speedX = 0;
int speedY = -1;

int defaultXPos = 160;
int defaultYPos = 25;

int XPos = defaultXPos;
int YPos = defaultYPos;

u64 actualTime = 0;


void printMatrixStatus(){
	//Print matrix info		
	for(int x = 0; x < 9; x++){
		for(int y = 0; y < 19; y++){
			printf("\x1b[%i;%iH%i ",y,x+8, gameTable[x][y]);
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

	// Create screens
	C3D_RenderTarget* top = C2D_CreateScreenTarget(GFX_TOP, GFX_LEFT);
	C3D_RenderTarget* bottom = C2D_CreateScreenTarget(GFX_BOTTOM, GFX_LEFT);

	//Init timer
	actualTime = osGetTime() + 800;

	initGame();

	// Main loop
	while (aptMainLoop())
	{
		hidScanInput();

		// Respond to user input
		u32 kDown = hidKeysDown();
		if (kDown & KEY_START){
			break; // break in order to return to hbmenu
		}

		if (kDown & KEY_DLEFT){
			XPos-=10;
			if(!canMove()){
				XPos+=10;
				printf("\x1b[22;0H You cannot move left");
			}
			
		}
		
		if(kDown & KEY_DRIGHT){
			if(!canMove()){
				XPos-=20;
				printf("\x1b[23;0H You cannot move right");
			}
			XPos+=10;
			
		}


		//printf("\x1b[10;15HTetris Game");
		//printf("\x1b[11;20HScore");

		// Render the scene
		C3D_FrameBegin(C3D_FRAME_SYNCDRAW);
		C2D_TargetClear(top, clrColor);
		C2D_SceneBegin(top);

		DrawBoard();
		//Game Loop
		if(osGetTime() > actualTime){
			YPos+=10;
			printMatrixStatus();
			DrawL(XPos, YPos);
			actualTime = osGetTime() + 800;
		}else{
			DrawL(XPos, YPos);
		}

		C3D_FrameEnd(0);
	}

	// Deinit libs
	DeInitAll();
	gfxExit();
	return 0;
}