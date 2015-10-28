#ifndef TOOLS
#define TOOLS

#include "types.h"
#include <stdlib.h>
#include <stdio.h>

int get_size_int(int* tab);
int get_size_char(char* tab);
void draw_graph(graph g);
void memorize(int* desert, int** res);
void copy(int* src, int* dest);
int reached_EOF(char* string);

#endif
