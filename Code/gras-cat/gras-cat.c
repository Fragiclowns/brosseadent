#include "gras-cat.h"


Result grascat(FilesIndex index) {

	if(index.allocatedFile == 0)
	{
		printf("cat: %s: does not exist\n", index.fileName);
		return Error;
	}

	if(index.fileType == 0)
	{
		printf("cat: %s: is a folder\n", index.fileName);
		return Error;
	}
	
	LinkedBlock *curseur = malloc(sizeof(LinkedBlock));
	curseur = index.firstBlock;
	
	if (curseur==NULL){
		printf("cat: %s: is empty\n", index.fileName);
		return Error;
	}
	
	while (curseur -> next != NULL){
		printf("%s", curseur -> data);
		curseur = curseur -> next;
	}
	printf("%s", curseur -> data);
				
}

void main() {
	FilesIndex index;
	
	LinkedBlock *block1 = malloc(sizeof(LinkedBlock));
	LinkedBlock *block2 = malloc(sizeof(LinkedBlock));
	LinkedBlock *block3 = malloc(sizeof(LinkedBlock));
	LinkedBlock *block4 = malloc(sizeof(LinkedBlock));
	
	block1 -> next = block2;
	block2 -> next = block3;
	block3 -> next = block4;
	block4 -> next = NULL;
	
	block1 -> data = "COUCOU1";
	block2 -> data = "COUCOU2\n";
	block3 -> data = "COUCOU3";
	block4 -> data = "COUCOU4\n";
	
	index.allocatedFile = 0;
	index.firstBlock = block1;
	index.lastBlock = block4;
    strcpy(index.fileName, "txt.txt");
    index.fileType = 0;

	grascat(index);
}