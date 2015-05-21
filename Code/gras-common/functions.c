#include "common.h"

FILE* fichier()
{
	FILE* fichier = fopen("/home/isen/Code/gras-common/txt.txt", "w+");
	fputs("Sam was here\n", fichier);
	return fichier;
}

FILE* writeFile(char* fileName, DiskImage imageToWrite)
{
	FILE* fToWrite = fopen(fileName, "w+");
	char buff[256];
	int i = 0;
	FilesIndex currentIndex;
	LinkedBlock *currentBlock = malloc(sizeof(LinkedBlock));
	currentBlock->next = NULL;

	// Save the Magic in the file
	fputs(imageToWrite.header.magic, fToWrite);

	// Save the version into the file
	// Format: major.minor
	sprintf(buff, "%c%d%c%d%c", SEPARATOR, imageToWrite.header.imageVersion.major, SEPARATOR, imageToWrite.header.imageVersion.minor, SEPARATOR);
	fputs(buff, fToWrite);
	sprintf(buff, "%d%c%d%c%d", imageToWrite.header.headerSize, SEPARATOR, imageToWrite.header.indexSize, SEPARATOR, imageToWrite.header.blockSize);
	fputs(buff, fToWrite);
	sprintf(buff, "%c%d%c%d\n", SEPARATOR, imageToWrite.imageSize, SEPARATOR, imageToWrite.filesNumber);
	fputs(buff, fToWrite);


	if (imageToWrite.filesNumber != 0)
	{
		for (i=0; i < imageToWrite.filesNumber; i++)
		{
			
			currentIndex = imageToWrite.index[i];
			sprintf(buff, "%d%c%d%c", currentIndex.allocatedFile, SEPARATOR, currentIndex.fileType, SEPARATOR);
			fputs(buff, fToWrite);

			sprintf(buff, "%d%c%s%c", currentIndex.parentFile, SEPARATOR, currentIndex.fileName, SEPARATOR);
			fputs(buff, fToWrite);

			sprintf(buff, "%d%c%d%c%d%c%d%c", currentIndex.creationDate.day, SEPARATOR, currentIndex.creationDate.month, SEPARATOR, currentIndex.creationDate.hour, SEPARATOR, currentIndex.creationDate.minutes, SEPARATOR);
			fputs(buff, fToWrite);

			sprintf(buff, "%d%c%d%c%d%c%d%c", currentIndex.lastModifDate.day, SEPARATOR, currentIndex.lastModifDate.month, SEPARATOR, currentIndex.lastModifDate.hour, SEPARATOR, currentIndex.lastModifDate.minutes, SEPARATOR);
			fputs(buff, fToWrite);
			
			sprintf(buff, "%d%c%d%c%d%c%d%c", currentIndex.lastAccessDate.day, SEPARATOR, currentIndex.lastAccessDate.month, SEPARATOR, currentIndex.lastAccessDate.hour, SEPARATOR, currentIndex.lastAccessDate.minutes, SEPARATOR);
			fputs(buff, fToWrite);

			currentBlock = currentIndex.firstBlock;
			while (currentBlock != NULL)
			{
				sprintf(buff, "%s\n", currentBlock->data);
				fputs(buff, fToWrite);
				if(currentBlock != NULL)
				{
					currentBlock = currentBlock->next;
				}
			}
			
		}
	}

	/*
		HU;IV;HS;IS;BS;imageSize; filesNumber
		index1: AF;FT;PF;NM;CD;MD;AD
		donnee1.1
		donnee1.2
		index2: AF;FT;PF;NM;CD;MD;AD
		donnee2.1
		donnee2.2
	*/
	
	return fToWrite;

}

DiskImage readFile(char* fileName)
{

}

void deleteLinkedList(LinkedBlock *block)
{
	free(block->data);

	if(block->previous != NULL)
	{
		deleteLinkedList(block->previous);
	}

	free(block);
}

/*
	Formating the writing of a given date
*/
Result writeDate(Date date)
{
	printf("|");
	if(date.day < 10){
		printf("0");
	}
	printf("%d ", date.day);

	printf("%s   ", months[date.month - 1]);

	if(date.hour < 10){
		printf("0");
	}
	printf("%d:", date.hour);

	if(date.minutes < 10){
		printf("0");
	}
	printf("%d|   ", date.minutes);

	return Ok;
}

FilesIndex *seekIndex(char *name, FilesIndex *indexes)
{
	int i;
	char fullName[256];
	FilesIndex cursorIndex = indexes[0], *toReturn;

	strcpy(fullName, name);

	for(i=0; emptyIndex.creationDate.day != cursorIndex.creationDate.day; i++)
	{
		cursorIndex = indexes[i];

		if(strcmp(cursorIndex.fileName, fullName) && cursorIndex.allocatedFile == 1)
		{
			toReturn = &cursorIndex;
			return toReturn;
		}
	}

	printf("The researched file/folder does not actually exists\n");
}

int sizeFile(FilesIndex *index,int blockSize){
	unsigned int count = 0;
	unsigned int size = 0;
	LinkedBlock *block = malloc(sizeof(LinkedBlock));
	block = index->firstBlock;
	while(block != NULL){
		count++;
		block = block->next;
		}
	size = (count * blockSize) + sizeof(FilesIndex);
	free(block);
	return size;	
}
