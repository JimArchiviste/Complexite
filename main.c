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
	int desert[] = {0,2,4};
	printf("%d\n",is_desert(desert, 3, g));
	return EXIT_SUCCESS;
}
