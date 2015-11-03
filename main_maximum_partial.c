#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "generate_graph.h"
#include "types.h"
#include "maximum_partial.h"
#include "tools.h"

int main (int argc, char *argv[])
{
	graph g;
	int i;

	if(argc < 2)
	{
		printf("[main_maximum_partial] ERREUR : you have to specify a file containing a graph as the first argument of the main.\n");
		return EXIT_FAILURE;
	}
	
	else
	{
		gen_graph(argv[1], &g);
		draw_graph(g);
		
		subgraph desert;
		for(i=0 ; i<NB_VERTICES ; i++) desert[i]=0;
		
		maximum_partial(g,desert);
		
		draw_subgraph(desert,g.n);
		
		return EXIT_SUCCESS;
	}
}
