#include <stdio.h>
#include <stdlib.h>

int main()
{
    printf("Welcome to Hangedman!\n");

    char guess;
    int attemptsleft=5;
    char word='a';
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
