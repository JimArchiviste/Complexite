#ifndef TOOLS
#define TOOLS

#include "types.h"
#include <stdlib.h>
#include <stdio.h>

void draw_graph(graph g);
void draw_subgraph(subgraph s, int n);
subgraph_list memorize(subgraph s, subgraph_list l);
void copy(subgraph src, subgraph dest);
int reached_EOF(char* string, size_t n);
int is_empty(subgraph s);
int length(subgraph s);
#endif
