#include <stdio.h>  
#include <stdlib.h>

void main() {
	int *ptr;
	ptr = malloc(2*sizeof(int));

	ptr[0] = 12;
	ptr[1] = 13;

	printf("%d\n", ptr[1]);

}