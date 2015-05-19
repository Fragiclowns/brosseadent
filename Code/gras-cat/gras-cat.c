
#include <stdio.h>
#include <stdlib.h>
#include "../gras-common/functions.c"


int grascat(FilesIndex index) {
	LinkedBlock *curseur = malloc(sizeof(LinkedBlock));
	curseur = index.firstBlock;
	
	if (curseur==NULL){
		printf("ERREUR");
		return 1;
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
	block2 -> data = "COUCOU2";
	block3 -> data = "COUCOU3";
	block4 -> data = "COUCOU4";
	
	
	index.firstBlock = NULL;
	index.lastBlock = block4;
    	

	grascat(index);
}

