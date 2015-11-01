#include "maximum_exact.h"

void desert_maximum_exact(graph g, int** res_set)
{
	desert_maximum_exact_rec(g, NULL, res_set, 0);
}

void desert_maximum_exact_rec(graph g, subgraph desert, int** res, int rank)
{
	//bool qu'on passe à faux si on a trouvé un maximal => pas la peine d'aller plus loin
	int go_on = 1;
	
	//si on est pas dans le premier appel récursif => desert non vide
	if(desert != NULL)
	{
		//on regarde s'il est desert maximal
		//et si oui on ne continue pas plus loin les appels récursifs, mais on stocke desert dans res
		if(is_maximal(desert, g) && is_desert(desert, g))
		{
			memorize(desert, res);
			go_on = 0;
			//évolution à ajouter : si notre graphe n'est pas désert, on pourrait mettre go_on à 0 => pas la peine de perdre du temps
		}
	}
	//si on était pas dnas le cas d'un désert maximal 
	if(go_on)
	{
		//rank est la profondeur d'appel récursif (changer de nom ?) => si on a une profondeur > g.n c'est terminé !
		if(rank <= g.n)
		{
			//on a deux cas : soit on ajoute un élément à lafin de notre sous ensemble de sommets, soit pas 
			int* desert1 = (int*)malloc(sizeof(desert));
			int* desert2 = (int*)malloc(sizeof(desert)+sizeof(int));
			//idem que memorize : à créer dans tools sans doute
			copy(desert, desert1);
			copy(desert, desert2);
			
			desert2[sizeof(desert)+1] = rank-1;
			
			free(desert);
			
			desert_maximum_exact_rec(g, desert1, res, rank+1);
			desert_maximum_exact_rec(g, desert2, res, rank+1);
		}
	}
}
