#ifndef DESERT_MAXIMUM_EXACT
#define DESERT_MAXIMUM_EXACT

#include "types.h"
#include "verification.h"
#include <stdlib.h>
#include <stdio.h>

void maximum_exact(graph g, subgraph max);
void maximum_exact_rec(graph g, subgraph desert, subgraph_list *res_list, int rank);
void extract_maximum(subgraph_list list, subgraph max);

#endif
