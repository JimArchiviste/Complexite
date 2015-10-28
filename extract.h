#ifndef MAXIMAL
#define MAXIMAL

#include "types.h"
#include "tools.h"
#include "verification.h"

int* extract_maximal(graph g);
void exMaximal_rec(int i, int* gmax, graph* g);
void exMaximal_incr(int* i, int* j, graph g);
void exMaximal_decr(int* i, int* j, graph g);

#endif
