#ifndef TYPE
#define TYPE

#define NB_VERTICES 10

typedef int vertex;								//a simple alias for lisibility

typedef struct
{
	int n;										//effective number of vertices of the graph
	int edges[NB_VERTICES][NB_VERTICES];
} graph;

typedef int subgraph[NB_VERTICES];

#endif
