#include "gras-fdisk.h"

void grasfdisk(int imageSize, int indexSize, int blockSize)
{
	Header newHeader;

	strcpy(newHeader.magic, magic);
	newHeader.imageVersion = versionActuelle;
	newHeader.headerSize = 10;
	newHeader.indexSize = indexSize;
	newHeader.blockSize = blockSize;

	/*
		Now we have our new fresh header, pretty well calibrated
		Let's get to the Index array now !
	*/

	FilesIndex *newIndex;
	int size = 0, iSize = indexSize;
	while(iSize >= sizeof(FilesIndex))
	{
		iSize -= sizeof(FilesIndex);
		size++;
		//We just count how many indexes we can stick
		//In the zone the user asked
	}

	newIndex = malloc(size*sizeof(FilesIndex));
	/*
		Regarding the demand of the user, we allocate a size array
		In order to have enough files
	*/

	DiskImage newImage;
	newImage.header = newHeader;
	newImage.index = newIndex;
	newImage.imageSize = imageSize;
	newImage.filesNumber = 0;
	/*
		The DiskImage is initializated, with all the interesting values
		Now, let's handle all the file's creation shit
	*/

	writeFile("txt.txt", newImage);
}


void main()
{
	grasfdisk(12, 4998, 12);
}