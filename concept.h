#ifndef __CONCEPT_H__
#define __CONCEPT_H__


	#include <stdio.h>
	#include <stdlib.h>
	#include <string.h>
	#include "init.h"

	#define NB_BLOCS_LARGEUR 9

void init_tab(char[81]);
char * NomCouleur(char);
void next_point(char[82], int *, int*);
void copy(char[81], char[81]);
int equal(char[81],char[81]);
int  valid_seq(int , int, char[81], int[81]);




#endif
