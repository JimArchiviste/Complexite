#include "tools.h"
#include "maximal.h"

/**auteur : Guélaud*/
int maximal(int* desert, graph g)
{
	int res,ig,ix,size_desert;
	res = 1;
	ig = 0;
	ix = 0;
	size_desert = tab_size(desert);
	while(res && ig < g.n)
	{
		while(desert[ix]==ig)
		{
			ig++;
		}
		int j = 1;
		while(j && ix < size_desert)
		{
			if(g.edges[ig][desert[ix]] == 1)
			{
				j = 0;
			}
			ix++;
		}
		ix = 0;
		ig++;
	}
	return res;
}
