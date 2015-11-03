#include "tools.h"

/**
 * \brief Draws a graph in the terminal
 * \param g The source graph
 * \author Alexandre Léonardi
 */
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

/**
 * \brief Draws a subgraph in the terminal
 * \param s The source subgraph
 * \param n The numer of vertices of s to take into account
 * \author Alexandre Léonardi
 */
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

/**
 * \brief Adds a subgraph to a subgraph list
 * \param s The subgraph to add
 * \param *l The list to be modified
 * \return The modified list
 * \author Alexandre Léonardi
 */
subgraph_list memorize(subgraph s, subgraph_list *l)
{
	element *tmp = (element*)malloc(sizeof(element));
	copy(s,tmp->s);
	tmp->next = *l;
	return tmp;	
}

/**
 * \brief Copy a subgraph into another
 * \param src The source subgraph
 * \param dest The destination subgraph that will be overwritter entirely
 * \author Alexandre Léonardi
 */
void copy(subgraph src, subgraph dest)
{
	int i;
	for(i=0 ; i<NB_VERTICES ; i++)
	{
		dest[i] = src[i];
	}
}

/**
 * \brief Checks if a string contains the end-of-file ('\0') character
 * \param string The string to check
 * \param n The size of the string
 * \return 1 if the string ends with '\0', 0 otherwise
 * \author Alexandre Léonardi
 */
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

/**
 * \brief Checks if a subgraph is empty (i.e. Contains only 0s)
 * \param g The subgraph to check
 * \return 1 if s is empty, 0 otherwise
 * \author Alexandre Léonardi
 */
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

/**
 * \brief Calculates the number of vertices in a subgraph
 * \param s The said subgraph
 * \return The number of vertices of the subgraph
 * \author Alexandre Léonardi
 */
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
