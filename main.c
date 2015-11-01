#include <stdlib.h>
#include <stdio.h>
#include "generate_graph.h"
#include "types.h"
#include "maximal.h"
#include "maximum_exact.h"
#include "verification.h"

int main (int argc, char *argv[])
{
	graph g;
	gen_graph("test", &g);
	subgraph desert;
	
	
	
	int i;
	for(i=0 ; i<NB_VERTICES ; i++){
		desert[i] = 0;
	}
	
	draw_graph(g);
	draw_subgraph(desert,g.n);
	
	//maximal(g,desert);
	//draw_subgraph(desert,g.n);
	
	maximum_exact(g,desert);
	draw_subgraph(desert,g.n);
	
	return EXIT_SUCCESS;
}
