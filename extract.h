#ifndef MAXIMAL
#define MAXIMAL

#include "types.h"
#include "tools.h"
#include "types.h"
#include "verification.h"

void extract_maximal(graph g, subgraph gmax);
void exMaximal_rec(int i, subgraph gmax, graph* g);
void exMaximal_incr(int* i, int* j, graph g);
void exMaximal_decr(int* i, int* j, graph g);

#endif
