#include "tools.h"

/**
 * \brief Calculates the length of an array
 * \param tab An array of any type
 * \return The length of the array
 * \author Alexandre Leonardi 	
 */
int get_size_int(int* tab)
{
	if(tab == NULL)
	{
		return 0;
	}
	return(sizeof(tab)/sizeof(int));
}

int get_size_char(char* tab)
{
	if(tab == NULL)
	{
		return 0;
	}
	return(sizeof(tab)/sizeof(char));
}


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


void memorize(int* desert, int** res)
{
	
	res = (int**)realloc(res, sizeof(desert) + sizeof(res));

}

void copy(int* src, int* dest)
{
	int n = get_size_int(src);
	int i;
	if(sizeof(src) != sizeof(dest))
	{
		printf("[tools/copy] ERROR : you can't an array into another  if they are not of the same length !");
	}
	for(i=0 ; i<n ; i++)
	{
		dest[i] = src[i];
	}
}

int reached_EOF(char* string)
{
	int n = get_size_char(string);
	int i;
	int eof = 0;
	while(i<n && !eof)
	{
		if(string[i] == '\0') eof=1;
		i++;
	}
	return eof;
}
