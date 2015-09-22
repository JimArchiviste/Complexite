#include verification.h


//auteur : Alexandre
int tab_size(void* tab)
{
	if(tab == NULL)
	{
		return 0;
	}
	return(sizeof(tab)/sizeof(tab[0]));
}

//auteur : Guélaud
int verification(int* desert, graph g)
{
	int res,i,j;
	res = 1;
	i = 0;
	j = 1;
	int size = tab_size(desert);
	while(i<size && res)
	{
		while(j<size && res)
		{
			if(g->edges[desert[i]][desert[j]])
			{
				res = 0;
			}
			j++;
		}
		i++;
		j = i+1;
	}
	return res;
}