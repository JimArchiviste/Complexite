#include "generate_graphe.h"

graph gen_graph(char *path)
{
	graph g;
	
	FILE* fichier = NULL;
	fichier = fopen(path, "r");
	char chaine[TAILLE_MAX] = "";
	
	if(fichier != NULL)
	{
		while (fgets(chaine, TAILLE_MAX, fichier) != NULL) // On lit le fichier tant qu'on ne reçoit pas d'erreur (NULL)
		{

			printf("%s", chaine); // On affiche la chaîne qu'on vient de lire

		}
	}
	
	return g;
}
