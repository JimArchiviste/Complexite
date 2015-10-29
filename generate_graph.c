#include "generate_graph.h"

#define MAX_SIZE 128

graph* gen_graph(char* path, graph *g)
{
	char *buffer, *charx, *chary;
	int i,j,x,y;

	FILE* file = NULL;
	if((file = fopen(path, "r")) == NULL)
	{
		printf("[generate_graph/gen_graph] ERROR : the specified path doesn't refer to an existiging file !\n");
	}
	else
	{
		buffer = (char*)malloc(sizeof(char)*MAX_SIZE);

		i = 0;
		while ( i < NB_VERTICES)
		{

			j = 0;
			while ( j < NB_VERTICES)
			{

				g->edges[i][j] = 0;
				j++;
			}
			i++;
		}

		i = 0;

		fgets(buffer, MAX_SIZE, file);
		g->n = atoi(strtok(buffer," "));

		while (fgets(buffer, MAX_SIZE, file) != NULL && !reached_EOF(buffer, sizeof(buffer)/sizeof(buffer[0])))
		{
			charx = strtok(buffer, " ");
			chary = strtok(NULL, " ");

			x = atoi(charx);
			y = atoi(chary);

			g->edges[x][y] = 1;
			g->edges[y][x] = 1;
		}
	free(buffer);
	}

	return g;
}
