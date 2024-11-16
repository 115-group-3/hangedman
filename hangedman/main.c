#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define MAX_WORD_LENGTH 20
#define MAX_GUESSES 6

void drawHangman(int attemptsleft) {
    switch (attemptsleft) {
        case 6:
            printf(" +----+ \n");
            printf(" |    | \n");
            printf("      | \n");
            printf("      | \n");
            printf("      | \n");
            printf("      | \n");
            printf(" ========= \n");
            break;
        case 5:
            printf(" +----+ \n");
            printf(" |    | \n");
            printf(" O    | \n");
            printf("      | \n");
            printf("      | \n");
            printf("      | \n");
            printf(" ========= \n");
            break;
        case 4:
            printf("  +---+ \n");
            printf("  |   | \n");
            printf("  O   | \n");
            printf("  |   | \n");
            printf("      | \n");
            printf("      | \n");
            printf(" ========= \n");
            break;
        case 3:
            printf(" +----+ \n");
            printf(" |    | \n");
            printf(" O    | \n");
            printf(" /|   | \n");
            printf("      | \n");
            printf("      | \n");
            printf(" ========= \n");
            break;
        case 2:
            printf(" +----+ \n");
            printf(" |    | \n");
            printf(" O    | \n");
            printf(" /|\\ | \n");
            printf("      | \n");
            printf("      | \n");
            printf(" ========= \n");
            break;
        case 1:
            printf(" +-----+ \n");
            printf(" |     | \n");
            printf(" O     | \n");
            printf(" /|\\  | \n");
            printf(" /     | \n");
            printf("       | \n");
            printf(" ========= \n");
            break;
        case 0:
            printf(" +-----+ \n");
            printf(" |     | \n");
            printf(" O     | \n");
            printf(" /|\\  | \n");
            printf(" / \\  | \n");
            printf("       | \n");
            printf(" ========= \n");
            break;
    }
}

int main()
{
    printf("Welcome to Hangedman!\n");

    char words[][MAX_WORD_LENGTH] = {"apple","banana","computer","door","elephant","flame"};
    int wordCount = sizeof(words) / sizeof(words[0]);
    int attemptsleft=6;
    char guess,word='a';
    while (attemptsleft > 0){
        system("cls");
        drawHangman(attemptsleft);


        printf("attempts remaining: %d\n", attemptsleft);
        printf("enter your guess: ");
        scanf(" %c",&guess);

        if (guess == word) {
            printf("correct\n");
            return 0;
        }
         else{
            printf("incorrect guess\npress any key to continue");
        }
        getchar();
        getchar();

        attemptsleft--;
    }



    return 0;
}
