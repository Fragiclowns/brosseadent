#include "gras-delete.h"

Result grasdelete(char *chemin, Result r, Result v, FilesIndex *indexes)
{
	/*
		All the variables are defined right here, right now
	*/

	FilesIndex *toDelete, *parentOne;
	char *toDeleteName = malloc(strlen(chemin)*sizeof(char));
	int i=strlen(chemin)-1, j=0, start, stop;

	/*
		First, let's obtain the file itself and it's parent
	*/

	stop = i;
	while(chemin[i] != '/')
		i--;
	start = i+1;
	for(i = start; i <= stop; i++)
	{
		toDeleteName[j] = chemin[i];
		j++;
	}

	printf("%s\n", toDeleteName);

	toDelete = seekIndex(toDeleteName, indexes);

}

void main()
{
	Result r, v;
	r.boolean = 0;
	v.boolean = 0;
	int i=0;

	//grasdelete("/pd/niquetout/txt.txt", r, v);
}