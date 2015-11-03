#include "maximum_exact.h"

/**
 * \brief Generates a desert maximum subgraph of a given graph
 * \param g The source graph
 * \param gmax The initialy empty subgraph to turn into a desert maximum subgraph
 * \author Alexandre Léonardi
 */
 //Complexity : theta(2^n)
void maximum_exact(graph g, subgraph max)
{
	subgraph tmp;
	clock_t time = clock();
	
	subgraph_list res_list = NULL;
	int i;
	for(i=0 ; i<NB_VERTICES ; i++) tmp[i]=0;
	maximum_exact_rec(g, tmp, &res_list, 0);
	
	extract_maximum(res_list, max);
	printf("[maximum_exact/maximum_exact] Execution time : %fs\n",(double)time/CLOCKS_PER_SEC);
}

/**
 * \brief Recursive function that generates all the subgraphs of a given graph and, if they are desert maximal, stores them in a list
 * \param g The source graph
 * \param desert A base subgraph that must be part of every other subgraph generated
 * \param *res_list the subgraphs list used to store them if they are desert maximal
 * \param depth The depth of the current recursive call, used as a stop condition and in order to know what subgraphs generate
 * \author Alexandre Léonardi
 */
void maximum_exact_rec(graph g, subgraph desert, subgraph_list *res_list, int depth)
{
	int go_on = 1;
		
	if(!is_empty(desert))
	{
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
	if(go_on)
	{
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

/**
 * \brief Searchs a maximum subgraph amng a list of maximals subgraphs
 * \param list The subgraphs list to search 
 * \param max The initialy empty subgraph bound to countain the maximum subgraph
 * \author Alexandre Léonardi
 */
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
