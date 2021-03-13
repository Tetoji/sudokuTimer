//Tetje Jannes Schulz

/*
#include <stdio.h>
#include <Windows.h>
#include <pthread.h>
#include <unistd.h>

int hour= 0, minute= 0, second= 0;
int eingabe;

int printData()
{
    printf("\r--------------------------------\n");
    printf("\r|        %d : %d : %d        |\n", hour, minute, second);
    printf("\r--------------------------------\n");
}

void counter(void * arg)
{
    while (eingabe != 99) 
    {
        printf("\r|        %d : %d : %d        |", hour, minute, second);
        second++;
        if(minute > 59) //after minute is greater than 59, reset minute and increase 1 hour
        {         
            minute = 0;++hour;
        }
        if(second > 59) //after second is greater than 59, reset second and increase 1 minute
        {        
            second = 0;++minute;
        }
        fflush(stdout);
        sleep(1);   //sleeps for one second
    }
}

int otherStuff()
{
    printf("\nEingabe: ");
    scanf("%d", &eingabe);
    printf("%d", eingabe);
}

int main() 
{
    pthread_t thread1, thread2;
    printf("\n--Timer--\n");
    pthread_create(&thread1, NULL, counter, NULL);
    pthread_join(thread1, NULL);
}
*/
//-----------------------------------------------------------------------------------------------------//
//-----------------------------------------------------------------------------------------------------//

#include <stdio.h>                      //LINKS:    https://stackoverflow.com/questions/7070346/c-best-way-to-get-integer-division-and-remainder
#include <time.h>                       //          https://levelup.gitconnected.com/8-ways-to-measure-execution-time-in-c-c-48634458d0f9
                                        //          https://www.geeksforgeeks.org/time-function-in-c/

//Global variables
time_t begin, end;  //to measure the time 
int minute = 0;
int hour = 0;
int eingabe;

int timeCount(time_t second)    //function to calculate the minutes, seconds and hours 
{
    if(second > 59) //after second is greater than 59, reset second and increase 1 minute
    {        
        minute = second / 60;
        second = second % 60;
    }
    if(minute > 59) //after minute is greater than 59, reset minute and increase 1 hour
    {         
        hour = minute / 60;
        minute = minute % 60;
    }
}

int main () 
{
    time(&begin);   // Start measuring time

    printf("--Errate die richtige Zahl zwischen 0 und 100--\n");

    do
    {    
        printf("Zahl: ");
        scanf("%d", &eingabe);
    } 
    while (eingabe!= 69);       //Richtige Zahl die zu erraten ist
    
    // Stop measuring time and calculate the elapsed time
    time(&end);     //Stop

    time_t second = end - begin;

    timeCount(second);  //function from above

    printf("\nGlückwunsch, die richtige Zahl ist 69!\n");
    printf("Gebrauchte Zeit:        %ld Std : %ld Min : %ld Sec        \n", hour, minute, second);

    return 0;
}