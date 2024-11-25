#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define MAX_WORD_LENGTH 100
#define MAX_GUESSES 6

void drawhangman(int attemptsleft) {
    switch (attemptsleft) {
        case 6:
            printf("  +-----+ \n");
            printf("  |     | \n");
            printf("        | \n");
            printf("        | \n");
            printf("        | \n");
            printf("        | \n");
            printf(" ========= \n");
            break;
        case 5:
            printf("  +-----+ \n");
            printf("  |     | \n");
            printf("  O     | \n");
            printf("        | \n");
            printf("        | \n");
            printf("        | \n");
            printf(" ========= \n");
            break;
        case 4:
            printf("  +-----+ \n");
            printf("  |     | \n");
            printf("  O     | \n");
            printf("  |     | \n");
            printf("        | \n");
            printf("        | \n");
            printf(" ========= \n");
            break;
        case 3:
            printf("  +-----+ \n");
            printf("  |     | \n");
            printf("  O     | \n");
            printf(" /|     | \n");
            printf("        | \n");
            printf("        | \n");
            printf(" ========= \n");
            break;
        case 2:
            printf("  +-----+ \n");
            printf("  |     | \n");
            printf("  O     | \n");
            printf(" /|\\    | \n");
            printf("        | \n");
            printf("        | \n");
            printf(" ========= \n");
            break;
        case 1:
            printf("  +-----+ \n");
            printf("  |     | \n");
            printf("  O     | \n");
            printf(" /|\\    | \n");
            printf(" /      | \n");
            printf("        | \n");
            printf(" ========= \n");
            break;
        case 0:
            printf("  +-----+ \n");
            printf("  |     | \n");
            printf("  O     | \n");
            printf(" /|\\    | \n");
            printf(" / \\    | \n");
            printf("        | \n");
            printf(" ========= \n");
            break;
    }
}

int main()
{
    int i;
    char words[][MAX_WORD_LENGTH] = {"apple","banana","computer","door","elephant","fire"};
    char hints[][MAX_WORD_LENGTH]={
    "A fruit that keeps doctors away",
    "A long yellow fruit",
    "Device used for computing",
    "Something you walk through in a house",
    "A very large animal",
    "It burns and gives light"};
    int wordcount = sizeof(words) / sizeof(words[0]); //used to find the number of elements in the 'word' array
    srand(time(NULL));
    int wordindex = rand() % wordcount; //select a random index for the word
    char selectedword[MAX_WORD_LENGTH];
    char selectedhint[MAX_WORD_LENGTH];
    strcpy(selectedword,words[wordindex]); //wordindex is an integer that represents a randomly selected index within this array
    strcpy(selectedhint,hints[wordindex]);
    int wordlength = strlen(selectedword); //finds the length of the word
    char guessedword[MAX_WORD_LENGTH];


    for(i=0;i<wordlength;i++)
    {
        guessedword[i] = '_'; //will display underscores for the letters to be guessed
    }

    guessedword[wordlength] = '\0';

    int attemptsleft = MAX_GUESSES;
    char guess;
    int correctguess;
    int fullyguessed;

    system("cls");

    printf("=====================================\n");
    printf("          Welcome to Hangman!       \n");
    printf("=====================================\n");
    printf("Guess the word by suggesting letters.\n");
    printf("You have %d chances to get it right.\n", MAX_GUESSES);
    printf("Good luck!\n");
    printf("Press enter to start...\n");
    getchar();

    while (attemptsleft > 0){
        system("cls");
        drawhangman(attemptsleft);

        printf("\nHint: %s\n",selectedhint);
        printf("\nWord: %s\n",guessedword);
        printf("Guess a letter: ",guess);

        if(scanf(" %c",&guess) != 1)
        {
            printf("Error: Invalid input.\n");
            printf("Press enter to continue...\n");
            getchar(); // consume newline character
            continue;
        }

        if (getchar() != '\n')
        {
            printf("Error: Please enter only one letter.\n");
            printf("Press enter to continue...\n");
            getchar();
            int c;
            while ((c = getchar()) != '\n' && c != EOF);
            continue;
        }

        if(!isalpha(guess))
        {
            printf("Error: Please enter an alphabet letter.\n");
            printf("Press enter to continue...\n");
            getchar();
            continue;
        }

        correctguess=0;
        for (int i=0;i<wordlength;i++)
        {
            if(selectedword[i]==guess){
                guessedword[i]=guess;
                correctguess=1;
            }
        }

        if(correctguess==0){
            attemptsleft--;
            printf("Incorrect guess.\nRemaining attempts: %d\n",attemptsleft);
            printf("Press enter to continue");
            getchar();
            }

        fullyguessed=1;     // initially assume the word is fully guessed
        for (int i=0;i<wordlength;i++)
        {
            if(guessedword[i]=='_') //to check if there are any unguessed letters
            {
                fullyguessed = 0;
                break;
            }
        }

        if(fullyguessed==1)
        {
            system("cls");
            drawhangman(attemptsleft);
            printf("\nWord: %s\n",guessedword);
            printf("Congratulations! You guessed the word.\n");
            return 0;
        }

    }

    system("cls");
    drawhangman(attemptsleft);
    printf("\n\nGame over. The word was '%s'.",selectedword);


    return 0;
}
