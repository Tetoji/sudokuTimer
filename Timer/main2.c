#include <stdio.h>
#include <stdlib.h>   //for exit(0), system("clear")


int hour= 0, minute= 0, second= 0, flag= 0;     //global variables
int choice;

void delay(ms)  //delay function
{
    clock_t timeDelay = ms + clock();    //Step up the difference from clock delay
    while (timeDelay > clock());         //stop when the clock is higher than time delay
}

int counterPrint()
{
    printf("|        %d : %d : %d        |", hour, minute, second);
}

int printData()
{
    printf("        1. Start | 2. End\n");
    printf("--------------------------------\n");
    counterPrint();
    printf("\n--------------------------------\n");
}

int counter()
{
    while(!fflush(stdout) && flag ==0) //keep looping while the user didn't hit any key and flag is 0
    {
        system("clear");
        if(minute > 59) //after minute is greater than 59, reset minute and increase 1 hour
        {         
            minute = 0;++hour;
        }
        if(second > 59) //after second is greater than 59, reset second and increase 1 minute
        {        
            second = 0;++minute;
        }
        printData();
        delay(1000);second += 1;    //print out the new data, delay for 1000 millisecond and increase 1 second.
    }
}

int main()
{
    printData();

    printf("Wahl: ");
    scanf("%d",  &choice);
    switch(choice)
    {
        case 1: counter();
        break;
    }

    return 0;
}