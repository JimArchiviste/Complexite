#include "maximum_exact.h"

void maximum_exact(graph g, subgraph max)
{
	subgraph tmp;
	subgraph_list res_list = NULL;
	int i;
	for(i=0 ; i<NB_VERTICES ; i++) tmp[i]=0;
	maximum_exact_rec(g, tmp, &res_list, 0);
	
	extract_maximum(res_list, max);
}

void maximum_exact_rec(graph g, subgraph desert, subgraph_list *res_list, int depth)
{
	//bool qu'on passe à faux si on a trouvé un maximal => pas la peine d'aller plus loin
	int go_on = 1;
		
	//si on est pas dans le premier appel récursif => desert non vide
	if(!is_empty(desert))
	{
		//on regarde s'il est desert maximal
		//et si oui on ne continue pas plus loin les appels récursifs, mais on stocke desert dans res
		if(is_desert(desert, g))
		{
			if(is_maximal(desert, g))
			{
				*res_list = memorize(desert, res_list);
				go_on = 0;
			}
		}
		else
		{
			go_on = 0;
		}
	}
	//si on était pas dnas le cas d'un désert maximal mais qu'on a quand même un graphe désert
	if(go_on)
	{
		//rank est la profondeur d'appel récursif (changer de nom ?) => si on a une profondeur > g.n c'est terminé !
		if(depth < g.n)
		{
			subgraph desert1, desert2;
			copy(desert, desert1);
			copy(desert, desert2);
			
			desert2[depth] = 1;
						
			maximum_exact_rec(g, desert1, res_list, depth+1);
			maximum_exact_rec(g, desert2, res_list, depth+1);
		}
	}
}

void extract_maximum(subgraph_list list, subgraph max)
{
	int size,longest;
	longest=-1; 
	
	if(list == NULL) printf("[maximum_exact/extract_maximum] You tried to get the longest subgraph among an empty list of subgraphs.");
	else
	{
		while(list != NULL)
		{
			size = length(list->s);
			if(size>longest)
			{
				longest = size;
				copy(list->s, max);
			}
			
			list = list->next;
		}
	}
}
