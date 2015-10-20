#ifndef GENERATE_DESERT_MAXIMUM_EXACT
#define GENERATE_DESERT_MAXIMUM_EXACT

#include "types.h"
#include "check.h"
#include <stdlib.h>
#include <stdio.h>

void desert_maximum_exact(graph g, int** res_set);
void desert_maximum_exact_rec(graph g, int* desert, int** res, int rank);

#endif
