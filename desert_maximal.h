 
#ifndef DESERT_MAXIMAL
#define DESERT_MAXIMAL

#include "types.h"
#include <stdlib.h>
#include <stdio.h>

void desert_maximum_exact(graph g, int** res_set);

void desert_maximum_exact_rec(graph g, int* desert, int** res, int rank);

#endif