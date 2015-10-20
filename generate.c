#include "generate.h"

#define TAILLE_MAX 1000

graph genGraph(char *path)
{
	graph g;
	
	FILE* fichier = NULL;
	fichier = fopen(path, "r");
	char chaine[TAILLE_MAX] = "";
	
	int i = 0;
	while ( i < NB_VERTICES)
	{
		int j = 0;
		while ( j < NB_VERTICES)
		{
			g->edges[i][j] = 0;
		}
	}
	
	if(fichier != NULL)
	{
		int i = 0;
		while (fgets(chaine, TAILLE_MAX, fichier) != NULL) // On lit le fichier tant qu'on ne reçoit pas d'erreur (NULL)
		{
			if(i != 0)
			{
				char * ichar = strtok (chaine," ");
				char * jchar = strtok (chaine," ");
				
				int i = atoi(ichar);
				int j = atoi(jchar);
				
				g->edges[i][j] = 1;
				g->edges[j][i] = 1;
			}
			i++;
		}
	}
	
	return g;
}
