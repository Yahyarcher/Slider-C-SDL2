#Constants

CC=gcc 
FLAGS=-Wall -Wextra  -g
SDLK=-lSDL2 -lSDL2_image -lSDL2_ttf



#Compilation


slider:main.o play.o animation.o concept.o init.o
	$(CC) -o slider main.o play.o animation.o concept.o init.o $(SDLK)


	
main.o:main.c main.h play.h animation.h concept.h init.h
	$(CC) -o main.o -c main.c $(FLAGS)	
	
play.o:play.c play.h animation.h concept.h init.h
	$(CC) -o play.o -c play.c $(FLAGS)	
	
animation.o:animation.c animation.h init.h
	$(CC) -o animation.o -c animation.c $(FLAGS)
	
concept.o:concept.c concept.h 
	$(CC) -o concept.o -c concept.c $(FLAGS)
	
init.o:init.c init.h 
	$(CC) -o init.o -c init.c $(FLAGS)
	
clear: 
	rm -ri *.o
