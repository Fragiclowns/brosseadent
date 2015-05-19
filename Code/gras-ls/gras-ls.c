#include gras-ls.h

unsigned i=0;


Result grasls ( FilesIndex *Index, Result l, Result c, Result a, char *ParentName ){
	while (Index[i]->allocatedFile == 1){
		if(ParentName == Index[i]->parentFile->fileName){
			printf("%s",Index[i]->fileName);
			if(	l == 0 ){
				if( c == 0 ){
					printf(" ; %d/%d %dh%d",Index[i]->creationDate->day,Index[i]->creationDate->month,Index[i]->creationDate->hour,Index[i]->creationDate->minutes)
				}
				if( a == 0 ){
					printf(" ; %d/%d %dh%d",Index[i]->lastAccessDate->day,Index[i]->lastAccessDate->month,Index[i]->lastAccessDate->hour,Index[i]->lastAccessDate->minutes);

				}
				if( c == 1 && a == 1 ){
					printf(" ; %d/%d %dh%d",Index[i]->lastModifDate->day,Index[i]->lastModifDate->month,Index[i]->lastModifDate->hour,Index[i]->lastModifDate->minutes);

				}

			}
			printf("\n");
		}
		i++;
	}
return 0;
}



void main(){



}