#include <stdlib.h>
#include <stdio.h>
#include "generate_graph.h"
#include "types.h"
#include "extract.h"

int main (int argc, char *argv[])
{
	graph *g = gen_graph("Benchs/anna");
        int* test = extract_maximal(*g);
        int i;
        for(i=0 ; i<g->n ; i++)
            printf("%d", test[i]);
        return EXIT_SUCCESS;
}
