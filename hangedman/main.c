#include <stdio.h>
#include <stdlib.h>
#define MAX_WORD_LENGTH 20
#define MAX_GUESSES 6

int main()
{
    printf("Welcome to Hangedman!\n");

    char words[][MAX_WORD_LENGTH]; = {"apple","banana","computer","door","elephant","flame"}
    int attemptsleft=6;
    while (attemptsleft > 0){
        printf("enter your guess: ");
        scanf(" %c",&guess);

        if (guess == word) {
            printf("correct\n");
            return 0;
        }
         else{
            printf("incorrect\n");
        }

        attemptsleft--;
        printf("attempts remaining: %d\n", attemptsleft);
    }



    return 0;
}
