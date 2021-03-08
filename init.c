#include "init.h"


int text_count = 0;


void init_graphics() {

	int flags = IMG_INIT_JPG;
	int initted;
	
	
	window = SDL_CreateWindow("SLIDER", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WINDOW_WIDTH, WINDOW_HEIGHT, SDL_WINDOW_RESIZABLE);
	

	if (!window)
	{
		fprintf(stderr, "Erreur d initialisation de la SDL : %s\n", SDL_GetError());
	}
	
	
	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED ); /*  SDL_RENDERER_SOFTWARE */
	

	if (renderer == 0) {
		fprintf(stderr, "Erreur d'initialisation de la SDL : %s\n", SDL_GetError());
	}
	

	
	if (TTF_Init() != 0)
	{
		fprintf(stderr, "Erreur d'initialisation TTF : %d\n", SDL_GetError());
	}

    police = TTF_OpenFont("stocky.ttf", 45);

    if (police == NULL) {
        fprintf(stderr,
                "\nTTF_OpenFont Error:  %s\n",
                SDL_GetError());
        exit(1);
    }

    
	initted = IMG_Init(flags);
	
	if((initted&flags) != flags)
	{
		printf("IMG_Init: Impossible d'initialiser le support des formats JPG et PNG requis!\n");
		printf("IMG_Init: %s\n", IMG_GetError());
	}
    
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 0);
	SDL_RenderClear(renderer);
    
}

void load_images(){
	
	
	int i;
	
	huf[0]= IMG_Load("slider0.png");
    huf[1]= IMG_Load("slider1.png");
    huf[2]= IMG_Load("slider2.png");
    huf[3]= IMG_Load("slider3.png");
    huf[4]= IMG_Load("slider4.png");
    huf[5]= IMG_Load("slider5.png");
    huf[6]= IMG_Load("slider6.png");
    huf[7]= IMG_Load("slider7.png");
	
	
	
	for (i = 0; i < 8; i++)
	{
		avatarat[i] = SDL_CreateTextureFromSurface(renderer, huf[i]);
	}
	for (i = 0; i < 8; i++)
	{
		SDL_FreeSurface(huf[i]);
	}
	
	
}





void cleanup_graphics() {
	//TTF_CloseFont(police);
	//TTF_Quit();
	for(int i = 0; i < text_count; i++) {
		SDL_DestroyTexture(text[i].texture);
	}
	text_count = 0;
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
}




void graphics_flip() {

	SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
	SDL_RenderPresent(renderer);
	SDL_RenderClear(renderer);
}




void graphics_generate_text(char *string) {
	SDL_Color color;
	SDL_GetRenderDrawColor(renderer, &color.r, &color.g, &color.b, &color.a);
	SDL_Surface *surface = TTF_RenderUTF8_Blended(police, string, color);
	if(!surface) {
		fprintf(stderr, "Erreur d'initialisation de la surface : %s\n", SDL_GetError());
		return;
	}
	SDL_Texture *texture = SDL_CreateTextureFromSurface(renderer, surface);
	SDL_FreeSurface(surface);
	if(!texture) {
		fprintf(stderr, "Erreur d'initialisation de la texture : %s\n", SDL_GetError());
		return;
	}
	text[text_count].string = string;
	text[text_count].texture = texture;
	text_count++;
}







void graphics_draw_texture(SDL_Texture *texture, int x, int y) {
	SDL_Rect drect = { x, y, 0, 0 };
	SDL_QueryTexture(texture, NULL, NULL, &drect.w, &drect.h);
	SDL_RenderCopy(renderer, texture, NULL, &drect);
}



void graphics_draw_string(char *string, int x, int y) {
	if(strcmp(string, "") == 0) return;
	for(int i = 0; i < text_count; i++) {
		if(strcmp(string, text[i].string)!=0) continue;
		graphics_draw_texture(text[i].texture, x, y);
		return;
	}
	
	graphics_generate_text(string);
	graphics_draw_texture(text[text_count-1].texture, x, y);
}



int graphics_string_width(char *string) {
	if(strcmp(string, "") == 0) return 0;
	for(int i = 0; i < text_count; i++) {
		if(strcmp(string, text[i].string)!=0) continue;
		int width;
		SDL_QueryTexture(text[i].texture, NULL, NULL, &width, NULL);
		return width;
	}
	return 0;
}



void graphics_draw_int(int n, int x, int y) {
	do {
		x -= 20;
		switch(n % 10) {
			case 0: graphics_draw_string("0", x, y); break;
			case 1: graphics_draw_string("1", x, y); break;
			case 2: graphics_draw_string("2", x, y); break;
			case 3: graphics_draw_string("3", x, y); break;
			case 4: graphics_draw_string("4", x, y); break;
			case 5: graphics_draw_string("5", x, y); break;
			case 6: graphics_draw_string("6", x, y); break;
			case 7: graphics_draw_string("7", x, y); break;
			case 8: graphics_draw_string("8", x, y); break;
			case 9: graphics_draw_string("9", x, y); break;
		}
		n /= 10;
	} while(n > 0);
}








