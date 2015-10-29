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


void memorize(int* desert, int** res)
{
	
	res = (int**)realloc(res, sizeof(desert) + sizeof(res));

}

void copy(int* src, size_t size_src, int* dest, size_t size_dest)
{
	int i;
	if(size_src != size_dest)
	{
		printf("[tools/copy] ERROR : you can't an array into another  if they are not of the same length !");
	}
	for(i=0 ; i<size_src ; i++)
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
