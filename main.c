#include <stdlib.h>
#include <stdio.h>
#include "generate_graph.h"
#include "types.h"
#include "extract.h"
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
	return EXIT_SUCCESS;
}
