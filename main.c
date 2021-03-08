#include "main.h"

int main() {

	int e = 0;
   
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {

        fprintf(stderr,
                "\nUnable to initialize SDL:  %s\n",
                SDL_GetError());

        return 1;
    }

	e = jouer();
	if (e)
	{
		TTF_CloseFont(police);
		TTF_Quit();
		init_graphics();
		afficherecranperte();
		cleanup_graphics();
	}
	
	


	SDL_Quit();
}
