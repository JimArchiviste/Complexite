#include "tools.h"

void draw_graph(graph g)
{
	int i, j;
	printf("nb sommets : %d\n",g.n);
	for(i = 0 ; i < g.n ; i++)
	{
		for(j = i ; j < g.n ; j++)
		{
			if(g.edges[i][j]) printf("[%d] <--> [%d]\n",i,j);
		}
	}
}

void draw_subgraph(subgraph s, int n)
{
	int i;
	if(n>0)
	{
		printf("[%d",s[0]);
		for(i=1 ; i<n ; i++) printf(";%d",s[i]);
	}
	printf("]\n");
}

subgraph_list memorize(subgraph s, subgraph_list *l)
{
	element *tmp = (element*)malloc(sizeof(element));
	copy(s,tmp->s);
	tmp->next = *l;
	return tmp;	
}

void copy(subgraph src, subgraph dest)
{
	int i;
	for(i=0 ; i<NB_VERTICES ; i++)
	{
		dest[i] = src[i];
	}
}

int reached_EOF(char* string, size_t n)
{
	int i;
	int eof = 0;
	while(i<n && !eof)
	{
		if(string[i] == '\0') eof=1;
		i++;
	}
	return eof;
}

int is_empty(subgraph s)
{
	int i,empty;
	empty = 1;
	i=0;
	while(i<NB_VERTICES && empty)
	{
		if(s[i]) empty = 0;
		i++;
	}
	return empty;
}

int length(subgraph s)
{
	int l,i;
	l=0;
	for(i=0;i<NB_VERTICES;i++)
	{
		if(s[i]) l++;
	}
	return l;
}

void enter_subgraph(subgraph s, int size_graph)
{
	int i;
	for(i=0 ; i<size_graph ; i++)
	{
		printf("Voulez-vous que ls sommet %d soit dans le sous-graphe ? (entrez 1 ou 0) : ",i);
		scanf("%d",&s[i]);	
	}
}
