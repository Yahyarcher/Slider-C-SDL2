#include "play.h"



	


int jouer(){
	
	SDL_Event event;
	
	char table[82];
	int  points = 0;
	int squares = 0;
	int destroyed = 0;
	int running = 1;
	int indice, precind, code=0, i;
	int prev[81];
	int width = 600, height=600;
	int end = 0;
	init_graphics();
	load_images();
	
	srand(time(NULL));
	init_tab(table);
	
	next_point(table, &squares, &end);
	updateboard(table, points, squares, "couleur");


	while (running) {

	while (SDL_PollEvent(&event))
	{
		switch(event.type)
		{
			case SDL_WINDOWEVENT:
				printf("window event\n");
				switch (event.window.event)
				{
					case SDL_WINDOWEVENT_CLOSE:
						printf("appui sur la croix\n");
						break;
					case SDL_WINDOWEVENT_SIZE_CHANGED:
						width = event.window.data1;
						height = event.window.data2;
						printf("Size : %d%d\n", width, height);
					default:
						
						running = 1;
				}
			    break;
			case SDL_MOUSEBUTTONDOWN:
				printf("Appui :%d %d\n", event.button.x, event.button.y);
					
				if ((event.button.x>112 && event.button.x<472)&&((event.button.y>70)&& (event.button.y<430)))
				{
				
					indice = ((event.button.x-112)/40) + ((event.button.y-70)/40)*9 ;
					printf("%d\n", indice);				
					if (table[indice]!= '0')
					{
						printf("%s\n ", NomCouleur(table[indice]));
						
							code = 1;
							precind = indice;
					}
					else
					{
						
							printf("empty \n");
							if (code)
							{
								
								if(valid_seq(precind, indice, table, prev))
								{
									destroyed = 0;
									doAnimation(precind,indice,table,prev,points,squares,NomCouleur(table[indice]));
									for (i = 9; i >4 ; i--)
									{
										destroy(i, table,&squares,&points,&destroyed);
									}
									
									if (destroyed == 0)
									{
										next_point(table, &squares, &end);
										if (end)
										{
											return end;
										}
									}
									destroy(5, table,&squares,&points,&destroyed);
								}
								else
								{
									printf("erreur\n\n");
									erreur();
								}
									
									
								
								code = 0;
								
								//updateboard(table, points, squares, NomCouleur(table[indice]));	 
							}	
					}
					updateboard(table, points, squares, NomCouleur(table[indice]));
					if (squares == 81)
					{
						
						return 1;
					}
						
					
						
				}
					
				
				break;
			case SDL_QUIT :
				printf("on quitte\n");
				running = 0;
			}
		}
	SDL_Delay(1);
	}
	cleanup_graphics();
	return 0;
	
}



void afficherecranperte(){
	
	SDL_Texture  *avatar;
	SDL_Rect pos;
	SDL_Surface * surf;
	
	init_graphics();
	
	
	surf= IMG_Load("youjustlost.png");
	avatar = SDL_CreateTextureFromSurface(renderer, surf);
	pos.x = pos.y = 0;
	pos.h = pos.w = 600;
	
	SDL_RenderCopy(renderer, avatar, NULL, &pos);
	SDL_RenderPresent(renderer);
	SDL_Delay(5000);
	SDL_FreeSurface(surf);
	
	
	
	
	
	
	
	
}




