#include <stdio.h>                      //LINKS:    https://stackoverflow.com/questions/7070346/c-best-way-to-get-integer-division-and-remainder
#include <time.h>                       //          https://levelup.gitconnected.com/8-ways-to-measure-execution-time-in-c-c-48634458d0f9
                                        //          https://www.geeksforgeeks.org/time-function-in-c/

//Globale Variablen
time_t begin, end;  //Um die Zeit zu messen

int seconds = 0;
int minute = 0;
int hour = 0;
int input;

int timeCount(time_t elapsed)    //Funktionen um die Sekunden, Minuten und Stunden zu errechnen 
{
    if(elapsed > 59) //Minuten rechnen
    {        
        minute = elapsed / 60;
        seconds = elapsed % 60;
           //Rest Sekunden
    }
    if(minute > 59) //Stunden rechnen
    {         
        hour = minute / 60;
        minute = minute % 60;   //Rest Minuten 
    }
}

int main () 
{
    time(&begin);   //Anfang des Counters

    printf("--Errate die richtige Zahl zwischen 0 und 100--\n");

    do
    {    
        printf("Zahl: ");
        scanf("%d", &input);
        
        if(input < 0 || input > 100)
        {
            printf("Bitte geben Sie eine gültige Zahl ein!\n\n");
        }
    } 
    while (input!= 69);     //Richtige Zahl die zu erraten ist
    
    time(&end);     //Stop der Erfassung der Zeit  

    time_t elapsed = end - begin;

    timeCount(elapsed);  //Funktion um die Minuten und Stunden zu berechnen

    printf("\nGlückwunsch, die richtige Zahl ist 69!\n");
    printf("Gebrauchte Zeit:        %ld Std : %ld Min : %ld Sec        \n", hour, minute, seconds);

    return 0;
}