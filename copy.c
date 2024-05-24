#include <stdio.h>
#include <stdlib.h>


int main(int argc,char **argv)
{	
	FILE *target,*source;
	int ch;
	
	if(argc!=3)
	{
		fprintf(stderr,"Usage %s source,target\n",argv[0]);
		exit(EXIT_FAILURE);
	}
	if((source =fopen(argv[1],"rb"))==NULL)
	{
		fprintf(stderr,"Error opening file %s\n",argv[1]);
		exit(EXIT_FAILURE);
	}
	if((target=fopen(argv[2],"wb"))==NULL)
	{
		fprintf(stderr,"Error writing file %s\n",argv[2]);
		exit(EXIT_FAILURE);
	}
	while((ch=getc(source))!=EOF)
	{
		putc(ch,target);
	}

	if (fclose(source) != 0)
        	printf("Could not close file %s\n", argv[1]);

        if (fclose(target) != 0)
        	printf("Could not close file %s\n", argv[2]);

    return 0;
}
