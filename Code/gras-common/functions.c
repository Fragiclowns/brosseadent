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
				if(currentBlock = NULL)
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
	*/
	

}