#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    
    FILE *fp;                // Pointer to the file 
    char ch;                // Character variable to read the content of file

    fp=fopen("demo.txt","w");                           //opening a file for writing mode 
    printf("Enter data (ctrl+d or '#' to quit):\n");

    if(fp==NULL)
    {
        fprintf(stderr,"Error opening file!\n");
    }
    while ((ch = getchar()) != EOF)
         {
            if(ch=='#')
                break;
            
                else
                    putc(ch, fp);
         }
    fclose(fp);                                         //closing file

    fp=fopen("demo.txt","r");               //opening a file for reading mode

    if(fp==NULL)
    {
        fprintf(stderr,"Error opening file!\n");
    }
    printf("\nData entered:\n");
    while ((ch = getc(fp)) != EOF) 
        {   
                 printf("%1c", ch);       
        }

    fclose(fp);                                 //closing file

    return 0;


}
