#include genereate_graphe.h
#include types.h
#include <stdlib.h>

void new_graph(int n)
{
	graph g;
	g.n = n;
	int i,j;
	i = 0;
	j = 1;
	while(i<n)
	{
		while(j<n)
		{
			int rand_num = rand() % 1;
			printf("%d", rand_num);			
			j++;
		}
		i++;
		j = i+1;
	}
	//return res;
}
