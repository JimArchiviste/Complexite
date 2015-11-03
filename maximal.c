#include "maximal.h"

/**
 * \brief Generates a desert maximal subgraph of a given graph
 * \param g The source graph
 * \param gmax The initialy empty subgraph to turn into a desert maximal subgraph
 * \author Loïc Vierin
 */
 //Complexity : theta(n^4)
void maximal(graph g, subgraph gmax)
{
	int i;
	clock_t time = clock();
	for(i= 0; i<g.n ; i++) gmax[i] = 0;
	i=0;
	
	while(i<g.n && !is_maximal(gmax,g))
	{
		gmax[i] = 1;
		if(!is_desert(gmax,g)) gmax[i] = 0;
		i++;
	}
	time = clock()-time;
	printf("[maximal/maximal] Execution time : %fs\n",(double)time/CLOCKS_PER_SEC);
}
