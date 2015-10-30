#include <stdlib.h>
#include <stdio.h>
#include "generate_graph.h"
#include "types.h"
#include "maximal.h"
#include "verification.h"

int main (int argc, char *argv[])
{
	graph g;
	gen_graph("test", &g);
	draw_graph(g);
	subgraph desert;
	int i;
	for(i=0 ; i<NB_VERTICES ; i++){
		desert[i] = 0;
	}
	desert[0] = 1;
	//desert[2] = 1;
	printf("%d\n",is_desert(desert, g));
	printf("%d\n",is_maximal(desert,g));
	draw_subgraph(desert,g.n);
	maximal(g,desert);
	draw_subgraph(desert,g.n);
	return EXIT_SUCCESS;
}
