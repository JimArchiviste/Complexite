#ifndef TYPE
#define TYPE

#define NB_VERTICES 1000

typedef int vertex;								//a simple alias for lisibility

typedef struct
{
	int n;										//effective number of vertices of the graph
	int edges[NB_VERTICES][NB_VERTICES];
} graph;

typedef struct LINK
{
	vertex v;
	struct link* next;
} link;

typedef link* vertices_set;

// List version of the graph representation
/*
typedef struct link
{
	vertex v;
	struct link* next;
}

typedef struct link* list;

typedef struct 
{
	int n;										//effective number of vertices of the graph
	list edges[NB_VERTICES];
} graph_l;
*/

#endif
