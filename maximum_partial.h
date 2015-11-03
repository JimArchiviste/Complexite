#ifndef MAXIMUM_INCOMPLET
#define MAXIMUM_INCOMPLET

#include "types.h"
#include "tools.h"
#include "verification.h"
#include <stdio.h>
#include <stdlib.h>

int vertex_with_less_edges(graph g, subgraph forbidden);
void maximum_partial(graph g, subgraph max);

#endif


