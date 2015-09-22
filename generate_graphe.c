#include "generate_graphe.h"

int new_graph(int n)
{
	/*graph g;
	g.n = n;*/
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
	return 1;
	//return res;
}
