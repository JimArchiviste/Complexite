#include "maximal.h"

void maximal(graph g, subgraph gmax)
{
	int i;
	for(i= 0; i<g.n ; i++) gmax[i] = 0;
	i=0;
	
	while(i<g.n && !is_maximal(gmax,g))
	{
		gmax[i] = 1;
		if(!is_desert(gmax,g)) gmax[i] = 0;
		i++;
	}
}
