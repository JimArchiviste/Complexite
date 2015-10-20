#ifndef MAXIMAL
#define MAXIMAL

#include "types.h"

graph exMaximal(graph g);
void exMaximal_rec(graph g, int i, int j, graph* gmax);
void exMaximal_incr(int* i, int* j, graph g);
graph exMaximum(graph g);

#endif
