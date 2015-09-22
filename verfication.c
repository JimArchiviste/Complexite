#include verification.h

/**
 * \brief Calculates the length of an array
 * \param tab An array of any type
 * \return The length of the array
 * \author Alexandre Leonardi 	
 */
int tab_size(void* tab)
{
	if(tab == NULL)
	{
		return 0;
	}
	return(sizeof(tab)/sizeof(tab[0]));
}

/**
 * \brief Checks if a set of vertices is a desert subgraph of a given graph
 * \param desert An array of int representing the subgraph to check
 * \param g The aforementioned graph
 * \return 1 if desert is a desert subgraph of g, 0 otherwise
 * \author Guélaud Lepetit
 */
int verification(int* desert, graph g)
{
	int res,i,j;
	res = 1;
	i = 0;
	j = 1;
	int size = tab_size(desert);
	while(i<size && res)
	{
		while(j<size && res)
		{
			if(g->edges[desert[i]][desert[j]])
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