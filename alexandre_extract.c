#include "tools.h"
#include "alexandre_extract.h"
#include "check.h"

void maximal(graph g, int* max)
{
	int i;

	//cette ligne n'est peut-être pas nécessaire ? à vérifier 
	max = (int*)malloc(sizeof(int)*g.n);

	for(i=0 ; i<g.n ; i++) max[i] = 0;

	max = maximal_rec(g, max,0);
}

int* maximal_rec(graph g, int* max, int depth)
{
	//est-ce qu'on a un sous graphe désert maximal ? si oui pas la peine de s'aventurer plus loin !
	if(is_maximal(max, g)) return max;

	//sinon, est-ce qu'on est à une profondeur d'appels récursifs inférieure au nombre de sommets dans l'arc ? 
	if(depth >= g.n) return NULL;
	else
	{
		//on rajoute le sommet correspondant à notre appel à max, mais si jamais il arrête d'être désert on l'enlève de suite après
		max[depth] = 1;
		if(!is_desert(max, g)) max[depth] = 0;
	}

	//maintenant, appel récursif en augmentant la profondeur d'un cran
	return maximal_rec(g,max,depth+1);
}
