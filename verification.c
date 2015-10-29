#include "verification.h"


/**
 * \brief Checks if a set of vertices is a desert subgraph of a given graph
 * \param desert An array of int representing the subgraph to check
 * \param g The aforementioned graph
 * \return 1 if desert is a desert subgraph of g, 0 otherwise
 * \author Guélaud Lepetit
 */
int is_desert(int* desert, size_t size, graph g)
{
	int res,i,j;
	res = 1;
	i = 0;
	j = 1;
	while(i<size && res)
	{
		while(j<size && res)
		{
			if(g.edges[desert[i]][desert[j]])
			{
				res = 0;
			}
			j++;
		}
		i++;
		j = i+1;
	}
	return res;
}

/**
 * \brief Checks if a set of vertices is a maximal desert subgraph of a given graph
 * \param desert An array of int representing the subgraph to check
 * \param g The aforementioned graph
 * \return 1 if desert is a desert subgraph of g, 0 otherwise
 * \author Guélaud Lepetit
 */
int is_maximal(int* desert, size_t size, graph g)
{
	int res,ig,ix,size_desert;
	res = 1;
	ig = 0;
	ix = 0;
	while(res && ig < g.n)
	{
		if(desert[ix] == ig)
		{
			ig++;
		}
		int tmp = 1;
		while(tmp && ix < size)
		{
			if(g.edges[ig][desert[ix]] == 1)
			{
				tmp = 0;
			}
			ix++;
		}
		if(tmp == 0)
		{
			res = 0;
		}
		ix = 0;
		ig++;
	}
	return res;
}
