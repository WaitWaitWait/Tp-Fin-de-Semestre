////////////////////////////////////////
//		Project Awalé Tp Fin S1		  //
//	     		_SDL.h				  //
//	By Valentin Monnot / Paul Marret  //
////////////////////////////////////////

#ifndef _SDL_H_
#define _SDL_H_

int SCREEN_WIDTH;
int SCREEN_HEIGHT;

typedef struct Config_s
{

	int Size_X;
	int Size_Y;
	int Music_State;
	int IaLevel;
	int Mode;
	int StartPlayer;
	int Advantage_P1;
	int Advantage_P2;

}Config;

Config LectureConfig();
#endif

