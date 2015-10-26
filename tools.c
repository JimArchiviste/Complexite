#include "tools.h"

/**
 * \brief Calculates the length of an array
 * \param tab An array of any type
 * \return The length of the array
 * \author Alexandre Leonardi 	
 */
int get_size(void* tab)
{
	if(tab == NULL)
	{
		return 0;
	}
	return(sizeof(tab)/sizeof(tab[0]));
}

void draw_graph(graph g)
{
	int* edges = g->edges;
	int nb_vertices = g->n;
	int i, j;
	for(i = 0 ; i < nb_vertices ; i++)
	{
		for(j = 0 ; j < nb_vertices ; j++)
		{
			if(i = 0)
			{
				printf("/t"+j);
			}
			else
			{
				if(j = 0)
				{
					printf(i);
				}
				else
				{
					printf("/t"+edges[i][j]);
				}					
			}
		}
	}
}


void memorize(int* desert, int** res)
{
	
	res = (int**)realloc(res, sizeof(desert) + sizeof(res));

}

void copy(void* src, voidvoid* dest)
{
	int n = get_size(src);
	int i;
	if(sizeof(src) != sizeof(dest))
	{
		printf("[tools/copy] ERROR : you can't an array into another  if they are not of the same length !");
	}
	for(i=0 ; i<n ; i++)
	{
		dest[i] = src[i];
	}
}