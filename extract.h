#ifndef MAXIMAL
#define MAXIMAL

#include "types.h"

graph extract_maximal(graph g);
void extract_maximal_rec(graph g, int i, int j, graph* gmax);
void extract_maximal_incr(int* i, int* j, graph g);
graph exMaximum(graph g);

#endif
