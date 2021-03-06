#ifndef TYPE
#define TYPE

#define NB_VERTICES 10

typedef struct
{
	int n;
	int edges[NB_VERTICES][NB_VERTICES];
} graph;

typedef int subgraph[NB_VERTICES];

typedef struct subgraph_list_elt{
	subgraph s;
	struct subgraph_list_elt *next;
} element;

typedef element *subgraph_list;
#endif
