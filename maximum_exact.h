#ifndef DESERT_MAXIMUM_EXACT
#define DESERT_MAXIMUM_EXACT

#include "types.h"
#include "verification.h"
#include <stdlib.h>
#include <stdio.h>

void desert_maximum_exact(graph g, int** res_set);
void desert_maximum_exact_rec(graph g, subgraph desert, int** res, int rank);

#endif
