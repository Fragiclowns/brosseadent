/*
	Every files to be included in every others
	Is specified right here
*/

#include <stdio.h> 
#include <string.h>  
#include <stdlib.h>
#include <ctype.h>
#include "conio.h"

#define SEPARATOR ';'
typedef struct version
{
	int major;
	int minor;
} Version;


char magic[2] = "HU";
Version versionActuelle = { 1, 0 };
/*
	A block structure that will be used as
	Linked Lists
*/
typedef struct block
{
	struct block *previous;
	struct block *next;
	char *data;
} LinkedBlock;

/*
	A bit-fielded Date structure
	Used in the Index of the Files
*/
typedef struct date
{
	int day :8;
	int month :8;
	int hour :8;
	int minutes :8;
} Date;

/*
	The Index Files structure
	Used in the Disk Image one
*/
typedef struct index
{
	/**
		Allocated File (AF) : 0/1
		Size: 1 bit

		File type (FT) : file (1)/directory (0)
		Size: 1 bit

		Parent File (PF) : a pointer to the Index of the Directory in which the file is
		'0x3FFF' if the position of the file is the root
		Size: 64 bits

		file NaMe (NM) : a string containing the name if the file
		Size: 2048 bits

		Creation Date (CD) : date of the file's creation:  day-month 	hour-minutes
		Size: 32 bits

		last Modification Date (MD) : date of the file's last modification:  day-month 	hour-minutes
		Size: 32 bits

		last Access Date (AD) : date of the file's last access:  day-month 	hour-minutes
		Size: 32 bits

		First Block (FB) : a pointer to the first data block of the file
		Size: 64 bits

		Last Block (LB) : a pointer to the last data block of the file
		Size: 64 bits
	**/
	
	unsigned allocatedFile :1;
	unsigned fileType :1;
	struct index *parentFile;
	char fileName[256];
	Date creationDate;
	Date lastModifDate;
	Date lastAccessDate;
	LinkedBlock *firstBlock;
	LinkedBlock *lastBlock;

} FilesIndex;

typedef struct header
{
	char magic[2];
	Version imageVersion;
	int headerSize;
	int indexSize;
	int blockSize;
} Header;

/**
	The main structure, the Image Disk one !
**/
typedef struct image 
{
	Header header;
	FilesIndex *index;
	int imageSize;
	int filesNumber;
} DiskImage;