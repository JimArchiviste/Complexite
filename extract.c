#include "tools.h"
#include "extract.h"

graph exMaximal(graph g)
{
	graph gmax;
	return desert_maximal2(g,0,0,*gmax);
}


graph exMaximal_rec(graph g, int i, int j, graph* gmax)
{
	if(i==j)
	{
		if(i==g.n-1)
			return gmax;		
	}
	
	
	else
	{
		if(g[i][j]=!1) 
		{
			//if(verif(gmax,j)) //verification dans gmax
			gmax.edges[i][j] = 1;
			gmax.edges[j][i] = 1;
		}
	}
		
		
	exMaximal_incr(&i,&j,g);			
	return exMaximal_rec(g,i,j,gmax);
	
}
				
		

void exMaximal_incr(int* i, int* j, graph g)
{
	if (*j == g.n )
	{
		
		*i = *i+1;
		*j = 0;
	}
	
	else
	{
		*j=*j+1;
	}
	
}



graph exMaximum(graph g)
{
	
}
