#include "tools.h"
#include "extract.h"

graph exMaximal(graph g)
{
	graph gmax;
	exMaximal_rec(g, 0, 0, &gmax, &g);
	return gmax;
}

void exMaximal_rec(graph g, int i, int j, graph* gmax, graph* g)
{
	if( ! Maximal(gmax, g) ) //si le sous graphe n'est pas maximal
	{
		if( verification(gmax, g) ) //si le sous graphe est bien un sous graphe desert
		{
				gmax->edges[i][j] = 1;
				gmax->edges[j][i] = 1;
				exMaximal_incr(&i,&j,g); //on avance
				exMaximal_rec(g,i,j,gmax,g);
			}
		else {
				exMaximal_decr(&i,&j,g);
				gmax->edges[i][j] = 0;
				gmax->edges[j][i] = 0;
		}
	}
	//sinon il est maximal
			
	
}
				
		

void exMaximal_incr(int* i, int* j, graph g)
{
	if (*j == g.n )
	{
		if( *i != g.n )
			*i = *i+1;
		*j = 0;
	}
	
	else
	{
		*j=*j+1;
	}
	
}


void exMaximal_decr(int* i, int* j, graph g)
{
	if (*j == 0 )
	{
		if(*i!= 0)
			*i = *i-1;
		*j = g.n;
	}
	
	else
	{
		*j=*j-1;
	}
	
}



graph exMaximum(graph g)
{
	
}
