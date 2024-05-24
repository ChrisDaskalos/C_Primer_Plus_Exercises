 //Enables to add words to a file,
 //by using the "a+" mode the program can both read and write
 //It creates the "wordadd" file and enables you to place words in it.
 //One word per line.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 41

int main(void)
{
	FILE *fp;
	char words[MAX];

	if((fp=fopen("wordadd","a+"))==NULL)							
	{
		fprintf(stdout,"Can't open \"wordadd\"file.\n");
			exit(EXIT_FAILURE);
			
	}

	puts("Enter words to add to the file : press the #");
	puts("key at the beginning of a line to terminate");
	while((fscanf(stdin,"%40s",words)==1)&&(words[0]!='#'))
		fprintf(fp,"%s\n",words);
	puts("File contents:");
	rewind(fp);								//takes the program to the file beginning 
											//so that the final while loop can print contents
	while(fscanf(fp,"%s",words)==1)
		puts(words);
	puts("Done!\n");
	if(fclose(fp)!=0)
		fprintf(stderr,"Error closing file.\n");


	return 0;
}
