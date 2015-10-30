#include "extract.h"


void extract_maximal(graph g, subgraph gmax)
{
	int i;
	for(i=0 ; i<g.n ; i++)
		gmax[i] = 0;
	
	exMaximal_rec(0, gmax, &g);
}

void exMaximal_rec(int i, subgraph gmax, graph* g)
{
	if( ! is_maximal(gmax, *g) && i!= g->n) //si le sous graphe n'est pas maximal
	{
		if( is_desert(gmax,  *g) ) //si le sous graphe est bien un sous graphe desert
		{
				gmax[i] = 1;
				i++;
				exMaximal_rec(i,gmax,g);
			}
		else {
				if(i!=0)
					gmax[i-1] = 0;
				else
					gmax[i]=0;
				exMaximal_rec(i+1,gmax,g);
		}
	}
	//sinon il est maximal
			
}
/*
graph extract_maximal(graph g)
{
	graph gmax;
	exMaximal_rec(0, 0, &gmax, &g);
	return gmax;
}

void exMaximal_rec(int i, int j, graph* gmax, graph* g)
{
	if( ! is_maximal(gmax, g) && i!= g->n && j!= g->n) //si le sous graphe n'est pas maximal
	{
		if( is_desert(gmax, g) ) //si le sous graphe est bien un sous graphe desert
		{
				gmax->edges[i][j] = 1;
				gmax->edges[j][i] = 1;
				exMaximal_incr(&i,&j,*g); //on avance
				exMaximal_rec(i,j,gmax,g);
			}
		else {
				exMaximal_decr(&i,&j,*g);
				gmax->edges[i][j] = 0;
				gmax->edges[j][i] = 0;

	
				exMaximal_incr(&i,&j,*g);
				exMaximal_incr(&i,&j,*g); //on saute le problème et on avance
				exMaximal_rec(i,j,gmax,g);
		}
	}
	//sinon il est maximal
			
}
* */



/*
1- Sous graphe mais pas maximal
1-1: Pas sous graphe
1-2: Pas sous graphe
1-3: Sous graphe non maximal
	1-3-1: pas sous graphe
	...
	1-3-5: sous graphe et maximal: arret final ?
1-..
...
2- sous graphe mais pas maximal
2-1: pas sous graphe
...
2-4: sous graphe non maximal
	2-4-1: non sous graphe
	...
	2-4-6: sous graphe maximal
...



*/
				
		

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
