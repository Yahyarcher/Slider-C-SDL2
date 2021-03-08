#ifndef __INIT_H__
#define __INIT_H__



	#include <stdio.h>
	#include <stdlib.h>
	#include <SDL2/SDL.h>
	#include <SDL2/SDL_image.h>
	#include <SDL2/SDL_ttf.h>

#define WINDOW_WIDTH 600
#define WINDOW_HEIGHT 600
#define MAX_TEXT 100

extern SDL_Window *window;
extern SDL_Renderer *renderer;
extern SDL_Texture *display;
extern TTF_Font *police;
extern  SDL_Texture  *avatarat[8];
SDL_Surface *huf[8];






struct { char *string; SDL_Texture *texture; } text[MAX_TEXT];




void init_graphics();
void load_images();
void cleanup_graphics();


void graphics_flip();
void graphics_draw_string(char *string, int x, int y);
int graphics_string_width(char *string);
void graphics_draw_int(int n, int x, int y);





#endif
