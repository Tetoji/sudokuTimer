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
