#include "tools.h"

/**
 * \brief Calculates the length of an array
 * \param tab An array of any type
 * \return The length of the array
 * \author Alexandre Leonardi 	
 */
int getSize(void* tab)
{
	if(tab == NULL)
	{
		return 0;
	}
	return(sizeof(tab)/sizeof(tab[0]));
}

void drawGraph(void* tab)
{
	int tab_size = getSize(tab);
	int i, j;
	for(i = 0 ; i < tab_size ; i++)
	{
		for(j = 0 ; j < tab_size ; j++)
		{
			if(i = 0)
			{
				printf("/t"+j);
			}
			else
			{
				if(j = 0)
				{
					printf(i);
				}
				else
				{
					printf(tab[i][j]);
				}					
			}
		}
	}
}
