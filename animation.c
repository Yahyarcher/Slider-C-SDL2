#include "animation.h"






void updateboard(char table[82], int points, int squares, char * color){
	int i,j;  
	rect.x = 112;
	rect.y = 70;
	rect.w = rect.h = 40;
	
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
	
		for (i = 0; i < 9; i++)
		{	
			for (j = 0; j < 9; j++)
			{
				SDL_RenderCopy(renderer, avatarat[table[i+9*j]-'0'], NULL, &rect);
				rect.y += 40;
			}
			rect.x += 40;rect.y = 70;
		}
		
		
		graphics_draw_string("Score: ", SCORE_X, SCORE_Y);
		graphics_draw_int(points, SCORE_X + graphics_string_width("Score: ") + 60, SCORE_Y);
		graphics_draw_string("Couleur: ", COLOR_X, COLOR_Y);
		graphics_draw_string(color, COLOR_X + graphics_string_width("Couleur: "), COLOR_Y);
		graphics_draw_string("Squares: ",  SQUARE_X, SQUARE_Y);
		graphics_draw_int(squares,  SQUARE_X + graphics_string_width("Squares: ") + 30, SQUARE_Y);
		
		
		graphics_flip();
		
		
}







void  markDestroy(int x, int * squares, int * points, int * destroyed) {
	*destroyed = 1;
	*squares -= x;
	*points += x * 2;
	
}

	
void destroy(int x, char table[82],  int * squares, int * points, int * destroyed) {
	char col;
	int ok = 0;
	int dd, ee,f;
	
	for (dd = 0; dd < NB_BLOCS_LARGEUR; dd++) {
		for (ee = 0; ee < NB_BLOCS_LARGEUR - x + 1; ee++) {
			 col = table[dd * NB_BLOCS_LARGEUR + ee];
			 ok = 1;
			if (col != '0') {
				for (f = ee + 1; f <= ee + x - 1; f++) {
					if ((table[dd * NB_BLOCS_LARGEUR + f] != col) &&
							(table[dd * NB_BLOCS_LARGEUR + f] != '7')) {
						if (col != '7') {
							ok = 0;
						} else {
							col = table[dd * NB_BLOCS_LARGEUR + f];
						}
					}
				}
				if (ok && (col != '0')) {
					markDestroy(x,squares,points, destroyed );
					for (f = ee; f <= ee + x - 1; f++) {
							table[dd * NB_BLOCS_LARGEUR + f] = '0';
						
						
					}
				}
			}
		}
	}
	for (dd = 0; dd < NB_BLOCS_LARGEUR - x + 1; dd++) {
		for (ee = 0; ee < NB_BLOCS_LARGEUR; ee++) {
			col = table[dd * NB_BLOCS_LARGEUR + ee];
			ok = 1;
			if (col != '0') {
				for (f = dd + 1; f <= dd + x - 1; f++) {
					if ((table[f * NB_BLOCS_LARGEUR + ee] != col) &&
							(table[f *NB_BLOCS_LARGEUR   + ee] != '7')) {
						if (col != '7') {
							ok = 0;
						} else {
							col = table[f * NB_BLOCS_LARGEUR  + ee];
						}
					}
				}
				if (ok && (col!='0')) {
					markDestroy(x,squares,points, destroyed );
					for (f = dd; f <= dd + x - 1; f++) {
							table[f * NB_BLOCS_LARGEUR + ee] = '0';
						
					}
				}
			}
		}
	}
	for (dd = 0; dd < NB_BLOCS_LARGEUR - x + 1; dd++) {
		for ( ee = 0; ee < NB_BLOCS_LARGEUR - x + 1; ee++) {
			 col = table[dd * NB_BLOCS_LARGEUR + ee];
			 ok = 1;
			if (col != '0') {
				for (f = dd + 1; f <= dd + x - 1; f++) {
					if ((table[f * NB_BLOCS_LARGEUR + ee + f - dd] != col) &&
							(table[f * NB_BLOCS_LARGEUR + ee + f - dd] != '7')) {
						if (col != '7') {
							ok = 0;
						} else {
							col = table[f * NB_BLOCS_LARGEUR + ee + f - dd];
						}
					}
				}
				if (ok && (col != '0')) {
					markDestroy(x,squares,points, destroyed );
					for (f = dd; f <= dd + x - 1; f++) {
							table[f * NB_BLOCS_LARGEUR + ee + f - dd] = '0';
						
					}
				}
			}
		}
	}
	for (dd = 0; dd < NB_BLOCS_LARGEUR - x + 1; dd++) {
		for (ee = x - 1; ee < NB_BLOCS_LARGEUR; ee++) {
			col = table[dd * NB_BLOCS_LARGEUR + ee];
			ok = 1;
			if (col != '0') {
				for (f = dd + 1; f <= dd + x - 1; f++) {
					if ((table[f * NB_BLOCS_LARGEUR + ee - f + dd] != col) &&
							(table[f * NB_BLOCS_LARGEUR + ee - f + dd] != '7')) {
						if (col != '7') {
							ok = 0;
						} else {
							col = table[f * NB_BLOCS_LARGEUR + ee - f + dd];
						}
					}
				}
				if (ok && (col != '0')) {
					markDestroy(x,squares,points, destroyed );
					for (f = dd; f <= dd + x - 1; f++) {
							table[f * NB_BLOCS_LARGEUR + ee - f + dd] = '0';
						
					}
				}
			}
		}
	}
	
}	



void chemin(int dest,int prev[81],int ta[81], int * taille){
	int i = 1, j=0 , x = dest;
	int tmp[81];

	tmp[0] = dest;
	
	
	while (prev[x] != -1)
	{
		x = prev[x];
		tmp[i] = x;
		i++;
	}
	
	
	for (j = 0; j < i; j++)
	{
		ta[j] = tmp[i-j-1] ;
	}
	//printf("%d  ",i);
	*taille = i;

}



void doAnimation(int source,int dest, char table[81], int prev[81], int points, int squares, char * color) {
	int ta[81];
	int taille;
	int i;
	
	chemin(dest, prev, ta,&taille);
	
	if (source == dest) {
		printf("\nfin animation\n");
	
	} else {
		
		for (i = 0; i<taille-1; i++)
		{
			table[ta[i+1]] = table[ta[i]];
			table[ta[i]] = '0';
			
			updateboard(table, points, squares, color);
			SDL_Delay(60);
		}
		
	}
}



void erreur(){
	
	SDL_Window *windowa;
	SDL_Renderer *renderera;
	SDL_Texture  *avatara;
	SDL_Rect posa;
	SDL_Surface * surfa;
	
	windowa = SDL_CreateWindow("SLIDER", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 500, 100, SDL_WINDOW_RESIZABLE);
	

	if (!windowa)
	{
		fprintf(stderr, "Erreur d initialisation de la SDL : %s\n", SDL_GetError());
	}
	
	
	renderera = SDL_CreateRenderer(windowa, -1, SDL_RENDERER_ACCELERATED ); /*  SDL_RENDERER_SOFTWARE */
	

	if (renderera == 0) {
		fprintf(stderr, "Erreur d'initialisation de la SDL : %s\n", SDL_GetError());
	}
	surfa= IMG_Load("impossible.png");
	avatara = SDL_CreateTextureFromSurface(renderera, surfa);
	posa.x = posa.y = 0;
	posa.h = 100; posa.w = 500;
	
	SDL_RenderCopy(renderera, avatara, NULL, &posa);
	SDL_RenderPresent(renderera);
	SDL_Delay(2500);
	SDL_FreeSurface(surfa);
	SDL_DestroyTexture(avatara);
    SDL_DestroyRenderer(renderera);
    SDL_DestroyWindow(windowa);
	
	
	
}


