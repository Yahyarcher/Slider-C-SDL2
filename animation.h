#ifndef __ANIMATION_H__
#define __ANIMATION_H__



	#include <SDL2/SDL.h>
	#include <SDL2/SDL_image.h>
	#include <SDL2/SDL_ttf.h>
	#include "init.h"

	#define NB_BLOCS_LARGEUR 9
	 
	#define COLOR_X 50
	#define COLOR_Y 10
	#define SCORE_X 300
	#define SCORE_Y 520
	#define SQUARE_X 10
	#define SQUARE_Y 520
	 
	//extern vars from graphics
	SDL_Window *window;
	SDL_Renderer *renderer;
	SDL_Texture *display;
	TTF_Font *police;
	SDL_Rect  rect;
	SDL_Texture  *avatarat[8];
	
	

	


	



	void updateboard(char[82], int , int , char *);
	void  markDestroy(int, int *, int *, int *) ;
	void destroy(int , char[82],  int *, int *, int *);
	void chemin(int,int[81],int[81], int *);
	void doAnimation(int ,int, char[81], int[81], int, int, char *);
	void erreur();







#endif
