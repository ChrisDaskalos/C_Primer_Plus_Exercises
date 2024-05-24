#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SIZE 100

void sort(int *arr,int n);
void printArr(const int *arr,int n);

int main(void)
{
	int arr[SIZE];	
	int range;
	printf("Enter number range: ");
	scanf("%d",&range);

	srand((unsigned)time(NULL));

	for(int i=0;i<SIZE;i++)
	{
		arr[i]=rand()%range+1;
		
	}
	puts("Initial Array\n");
	printArr(arr,SIZE);
	sort(arr,SIZE);
	puts("Sorted array\n");
	printArr(arr,SIZE);

	
	return 0;
}
void sort(int *arr,int n)
{
	int temp;
	int top,seek;

	for(top=0;top<n-1;top++)
	{
		for(seek=top+1;seek<n;seek++)
			if(arr[seek]>arr[top])
			{
				temp=arr[top];
				arr[top]=arr[seek];
				arr[seek]=temp;
			}
	}
}
void printArr(const int *arr,int n)
{
	int index;
	for(index=0;index<n;index++)
	{
		printf("%5d",arr[index]);
		if (index % 10 == 9)
            putchar('\n');
	}
	if (index % 10 != 0) // if last line not complete
        putchar('\n');
}

