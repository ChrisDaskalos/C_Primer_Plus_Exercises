#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

int days(int day,char *mon,int year);
int days_heap(int day,char *mon,int year);

struct month{
    char name[10];  
    char abbrev[4]; 
    int days;   
    int monumb; 
};

const struct month months[12] ={        //read-only array of structs
        {"January", "Jan", 31, 1},
        {"February", "Feb", 28, 2},
        {"March", "Mar", 31, 3},
        {"April", "Apr", 30, 4},
        {"May", "May", 31, 5},
        {"June", "Jun", 30, 6},
        {"July", "Jul", 31, 7},
        {"August", "Aug", 31, 8},
        {"September", "Sep", 30, 9},
        {"October", "Oct", 31, 10},
        {"November", "Nov", 30, 11},
        {"December", "Dec", 31, 12}
};
const struct month months_heap[12] ={      //leap year ,29 days in feb  
        {"January", "Jan", 31, 1},
        {"February", "Feb", 29, 2},
        {"March", "Mar", 31, 3},
        {"April", "Apr", 30, 4},
        {"May", "May", 31, 5},
        {"June", "Jun", 30, 6},
        {"July", "Jul", 31, 7},
        {"August", "Aug", 31, 8},
        {"September", "Sep", 30, 9},
        {"October", "Oct", 31, 10},
        {"November", "Nov", 30, 11},
        {"December", "Dec", 31, 12}
};


int main(void)
{
    int day;
    int year;
    char name[20];
    int totaldays;
    printf("Enter the day number(1-30): ");

    while(scanf("%d",&day)==1)
    {   
        if(day<1 || day>30)
        {
            printf("Only values between 1-30 are acceptable.\n");
            printf("Enter a valid number: ");
            continue;        
        }
        printf("Enter the month: ");
        scanf("%20s",name);
        printf("Enter the year: ");
        scanf("%d",&year); 
        if(year%4==0 && year%400 != 0)
            totaldays=days_heap(day,name,year);
        else
            totaldays=days(day,name,year);
        if(totaldays>0)
            printf("There are %d days through %s days %d in year %d.\n", totaldays, name, day, year);
        else
            printf("%s is not valid input.\n", name);
        printf("Please enter the day (character to quit): ");
    }
    puts("bye");

    return 0;


}

int days(int day,char *mon,int yr)
{
    int i,    
        total=0,
        mon_num;
    if(isalpha(*mon))
    {
        mon[0]=toupper(mon[0]);
        for(i=1;mon[i]!='\0';i++)
            mon[i]=tolower(mon[i]);
    }
    for(i=0;i<12;i++)
    {
        if(strcmp(mon,months[i].name) == 0 || strcmp(mon,months[i].abbrev) == 0 || atoi(mon) == months[i].monumb)
        {
            mon_num=months[i].monumb;
            break;
        }
    }
    if(mon_num==0)
        total=-1;
    else
        for(i=0;i<=mon_num-1;i++)
            total+=months[i].days;
     
    
        return total;
}

int days_heap(int day,char *mon,int yr)
{
    int i,    
        total=0,
        mon_num;
    if(isalpha(*mon))
    {
        mon[0]=toupper(mon[0]);
        for(i=1;mon[i]!='\0';i++)
            mon[i]=tolower(mon[i]);
    }
    for(i=0;i<12;i++)
    {
        if(strcmp(mon,months[i].name) == 0 || strcmp(mon,months[i].abbrev) == 0 || atoi(mon) == months[i].monumb)
        {
            mon_num=months[i].monumb;
            break;
        }
    }
    if(mon_num==0)
        total=-1;
    else
        for(i=0;i<=mon_num-1;i++)
            total+=months[i].days;
        
    
        return total;
}

