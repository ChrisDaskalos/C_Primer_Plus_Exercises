#include "diceroll.h"
#include <stdio.h>
#include <stdlib.h>		//for library rand()

int roll_count=0;		//external linkage

static int rollem(int sides)	//private to this file
{
	int roll;
	roll=rand()%sides+1;
	++roll_count;			//count function calls

	return roll;
}
int roll_n_dice(int dice,int sides)
{
	int d;
	int total=0;

		while(sides<2)
		{
		printf("Need at least 2 sides.\n");
			return 1;
		}
		
	
	
		while(dice<1)
			{
			printf("Need at least 1 die.\n");
				return -1;
			}
	
	for(d=0;d<dice;d++)
		total+=rollem(sides);
	return total;
}
