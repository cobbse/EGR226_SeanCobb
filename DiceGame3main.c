#include <stdio.h>
#include <stdlib.h>
#include "DiceGame3.c"
#include <string.h>

int main()
{
    char camount[4], bamount[4];
    int creds, wager, valid;
    char ans;
    //welcome user to the game
    printf("Welcome to the dice game!\n");

    //call credits function
    creds = credits(camount);
    do{

        //call bet function
        wager = bet(creds, bamount);

        //let user know what is coming next
        printf("\nA random will be rolled for you and the computer from 1-6\n");

        //call compare function
        creds = compare(creds, wager);

        //ask if they want to play again and check for errors
        valid = 0;
        while(valid == 0){
        printf("Play again? (y/n)");
        scanf("%c", &ans);
        if(ans == 'y' || ans == 'Y' || ans == 'n' || ans == 'N'){
            valid = 1;
        }
        else{
            printf("\nInvalid entry, try again.\n");
            fflush(stdin);
            valid = 0;
        }
    }
    }while(ans == 'y' || ans == 'Y');
    return 0;
}
