#include "maximum_partial.h"

/**
 * \brief Searches the vertex with the less edges in a given graph
 * \param g The source graph
 * \param forbidden A set of vertices to ignore during the search
 * \author Abdelkader Benameur
 * \return The index of the found vertex
 */
int vertex_with_less_edges(graph g, subgraph forbidden)
{
	int nbEdges;
	int nbEdgesMin = NB_VERTICES*NB_VERTICES;
	int index = -1;
	int i,j;
	
	for(i=0 ; i<g.n ; i++)
	{
		nbEdges = 0;
		if(!forbidden[i])
		{
			for(j=i+1 ; j<g.n ; j++)
			{
				if(!forbidden[j] && g.edges[i][j]) nbEdges++;
			}
			if(nbEdges < nbEdgesMin)
			{	
				nbEdgesMin = nbEdges;
				index = i;
			}
		}
	}
	return index;
}

/**
 * \brief Using an heuristic, generates a subgraph as close to maximum as  possible
 * \param g The source graph
 * \param max The initialy empty subgraph to turn into a desert maximum subgraph
 * \author Abdelkader Benameur
 */
 //Complexity : theta()
void maximum_partial(graph g, subgraph max)
{
	int index,i;
	subgraph forbidden;
	
	for(i=0 ; i<NB_VERTICES ; i++) forbidden[i] = 0;
	
	while(!is_maximal(max,g))
	{
		index = vertex_with_less_edges(g,forbidden);
		forbidden[index] = 1;
		max[index] = 1;
		//rajouter tous les successeurs de index à forbidden si c utile
		if(!is_desert(max,g)) max[index] = 0;
	}
}
