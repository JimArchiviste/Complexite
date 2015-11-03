#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "generate_graph.h"
#include "types.h"
#include "verification.h"

int main (int argc, char *argv[])
{
	graph g;

	if(argc < 2)
	{
		printf("[main_is_maximal] ERREUR : you have to specify a file containing a graph as the first argument of the main.\n");
		return EXIT_FAILURE;
	}
	
	else
	{
		gen_graph(argv[1], &g);
		draw_graph(g);
		
		subgraph desert;
		enter_subgraph(desert,g.n);
		draw_subgraph(desert,g.n);
		
		printf("Le sous-graphe est-il désert maximal ?\n");
		if(is_maximal(desert,g)) printf("Oui !\n");
		else printf("Non :(\n");
		
		return EXIT_SUCCESS;
	}
}
