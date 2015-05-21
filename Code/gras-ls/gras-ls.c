#include "gras-ls.h"

Result grasls (FilesIndex toDescribe, Result l, Result c, Result a)
{
	if(toDescribe.allocatedFile == 0)
	{
		printf("Error: the file is not allocated\n");
		return Error;
	}
	
	if (toDescribe.fileType == 1)
	{
		Date date;
		if(a.boolean == 1)
		{
			date = toDescribe.lastAccessDate;
			writeDate(date);
		}

		if(c.boolean == 1)
		{
			date = toDescribe.creationDate;
			writeDate(date);
		}

		if(l.boolean == 1)
		{
			date = toDescribe.lastModifDate;
			writeDate(date);
		}

		printf("%s\n", toDescribe.fileName);

		return Ok;
	}

	if (toDescribe.fileType == 0)
	{
		int i;
		LinkedBlock *curseur = malloc(sizeof(LinkedBlock));
		FilesIndex curIndex;
		FilesIndex *data = malloc(10*sizeof(LinkedBlock));

		curseur = toDescribe.firstBlock;
		int genericSize = curseur->dataSize;

		while(curseur != NULL)
		{
			data = curseur->data;
			for(i=0; i < curseur->dataSize; i++)
			{
				if(i = curseur->dataSize - 1 && curseur->dataSize < genericSize)
					return Ok;

				curIndex = data[i];

				if(curIndex.allocatedFile == 1)
				{
					curIndex.fileType = 1;
					grasls(curIndex, l, c, a);
				}
			}
			curseur = curseur->next;
		}

		return Ok;		
	}
}



void main(){
	FilesIndex index;
	Result l, a, c;
	l.boolean = 1;
	c.boolean = 1;
	a.boolean = 1;
	index.fileType = 1;

	Date date;
	date.day = 1;
	date.month = 1;
	date.hour = 1;
	date.minutes = 1;
	index.creationDate = date;

	date.day = 3;
	date.month = 3;
	date.hour = 3;
	date.minutes = 3;
	index.lastModifDate = date;

	date.day = 4;
	date.month = 4;
	date.hour = 4;
	date.minutes = 4;
	index.lastAccessDate = date;

	strcpy(index.fileName, "txt.txt");
	grasls(index, l, c, a);
}