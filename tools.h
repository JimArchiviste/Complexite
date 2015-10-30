#ifndef TOOLS
#define TOOLS

#include "types.h"
#include <stdlib.h>
#include <stdio.h>

void draw_graph(graph g);
void memorize(int* desert, int** res);
void copy(int* src, size_t size_src, int* dest, size_t size_dest);
int reached_EOF(char* string, size_t n);
#endif
