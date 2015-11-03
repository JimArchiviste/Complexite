#include "verification.h"


/**
 * \brief Checks if a set of vertices is a desert subgraph of a given graph
 * \param desert An array of int representing the subgraph to check
 * \param g The aforementioned graph
 * \return 1 if desert is a desert subgraph of g, 0 otherwise
 * \author Guélaud Lepetit
 */
int is_desert(subgraph desert, graph g)
{
	int res,i,j;
	clock_t time = clock();
	res = 1;
	i = 0;
	j = 1;
	while(i<g.n && res)
	{
		while(j<g.n && res)
		{
			if(desert[i] && desert[j] && g.edges[i][j])
			{
				res = 0;
			}
			j++;
		}
		i++;
		j = i+1;
	}
	time = clock()-time;
	printf("[verification/is_desert] Execution time : %f\n",(double)time/CLOCKS_PER_SEC);
	return res;
}

/**
 * \brief Checks if a set of vertices is a maximal desert subgraph of a given graph
 * \param desert An array of int representing the subgraph to check
 * \param g The aforementioned graph
 * \return 1 if desert is a desert subgraph of g, 0 otherwise
 * \author Guélaud Lepetit
 */
int is_maximal(subgraph desert, graph g)
{
	int res,i;
	res = 1;
	i = 0;
	if(!is_desert(desert,g)) res=0;
	else
	{
		while(res && i<g.n)
		{
			if(!desert[i])
			{
				desert[i] = 1;
				res = !is_desert(desert,g);
				desert[i] = 0;
			}
			i++;
		}
	}
	return res;
}
