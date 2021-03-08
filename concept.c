#include "concept.h"




void init_tab(char table[81]){
	int i;
	
	for (i = 0; i < 81; i++)
	{
		table[i] = '0';
	}
}




char * NomCouleur(char code){
		char * couleur = NULL;
		char * vide = "empty";
		char * blue = "blue";
		char * brown = "brown";
		char * red = "red";
		char * pink = "pink";
		char * joker = "joker";
		char * green = "green";
		char * yellow = "yellow";
		
		if(code=='0') couleur = vide;
		if(code=='1') couleur = yellow;
		if(code=='2') couleur = blue;
		if(code=='3') couleur = brown;
		if(code=='4') couleur = green;
		if(code=='5') couleur = red;
		if(code=='6') couleur = pink;
		if(code=='7') couleur = joker;
		
		return couleur;
		
}








void copy(char table[81], char table2[81]){
	int i;
	for (i = 0; i < 81; i++)
	{
		table2[i] = table[i];
	}
}
int equal(char tab[81],char table[81]){
	int i= 0, res = 0;
	while (tab[i] == table[i])
	{
		i++;
	}
	if (i == 81 ) res = 1;
	
	return res;
	
}


int  valid_seq(int x, int y, char table[81], int prev[81]){
	
	int t,l, res = 0;
	char table2[81];
	char  backtable[81];
	
	
	for (t = 0; t <= NB_BLOCS_LARGEUR * NB_BLOCS_LARGEUR; t++) {
		prev[t] = -1;
	}
	copy(table, backtable);
	table[y] = '0';
	copy(table, table2);
	table2[x] = '9';
	while (!equal(table, table2)) {
		//table = table2;
		
		copy(table2, table);
		
		for (l = 0; l < NB_BLOCS_LARGEUR * NB_BLOCS_LARGEUR; l++) {
			if (table[l] == '9') {
				if (l >= NB_BLOCS_LARGEUR) {
					if (table[l - NB_BLOCS_LARGEUR] == '0') {
						table2[l - NB_BLOCS_LARGEUR] = '9';
						prev[l - NB_BLOCS_LARGEUR] = l;
					}
				}
				if (l % NB_BLOCS_LARGEUR != 0) {
					if (table[l - 1] == '0') {
						table2[l-1] = '9';
						prev[l - 1] = l;
					}
				}
				if (l % NB_BLOCS_LARGEUR != NB_BLOCS_LARGEUR - 1) {
					if (table[l + 1]=='0') {
						table2[l+1] = '9';
						prev[l + 1] = l;
					}
				}
				if (l < NB_BLOCS_LARGEUR * NB_BLOCS_LARGEUR - NB_BLOCS_LARGEUR) {
					if (table[l + NB_BLOCS_LARGEUR] == '0') {
						table2[l + NB_BLOCS_LARGEUR] = '9';
						prev[l + NB_BLOCS_LARGEUR] = l;
					}
				}
			}
		}
	}
	copy(backtable, table);
	if (table2[y] == '9') {
		res = 1;
	}
	
	return res;
}



void next_point(char table[82], int * squares, int* end){
	int place1, place2, place3;
	
	if (*squares < 79)
	{
		place1 = rand()%81;
		while (table[place1] != '0')
		{
			place1 = rand()%81;
		}table[place1] = rand()%7 + '0' +1;
		
		place2 = rand()%81;
		while (table[place2] != '0' || place2 == place1)
		{
			place2 = rand()%81;
		}table[place2] = rand()%7 + '0' + 1;
		
		place3 = rand()%81;
		while (table[place3] != '0' || place3 == place1 || place3 == place2)
		{
			place3 = rand()%81;
		}table[place3] = rand()%7 + '0'+ 1;
		
		*squares+=3;
		
	}else
	{
		printf("you lost");
		printf("%d ", *end);
		*end = 1;
		printf("%d ", *end);
	}
	
}

