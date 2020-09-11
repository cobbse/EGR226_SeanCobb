#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>

//ask user for credits amount and check for errors and output integer value
int credits(char camount[]){
    int number, i, check, x;
    fflush(stdin);
    check = 0;
    number = 0;
    while(check == 0){
        printf("Enter credits up to 999: ");
        for(i = 0; scanf("%c", &camount[i]) != '\0'; i++){
            if(camount[i] >= 0 && isdigit(camount[i]) != 0){
                number++;
                check = 1;
                if(number > 3){
                    printf("\nInvalid entry, try again.\n");
                    fflush(stdin);
                    check = 0;
                    number = 0;
                    break;
                }
            }
            else if(camount[i] == '\n'){
                check = 1;
                break;
            }
            else{
                printf("\nInvalid entry, try again.\n");
                fflush(stdin);
                check = 0;
                break;
            }
        }
    }

    switch(number){

        //convert array from type char to type int
        case 1:
                x = ((int)camount[0] - 48);
                break;
        case 2:
                x = (((int)camount[0] - 48) * 10) + ((int)camount[1] - 48);
                break;
        case 3:
                x = (((int)camount[0] - 48) * 100) + (((int)camount[1] - 48) * 10) + ((int)camount[2] - 48);
                break;

        default:
                printf("\nError in code, run program again.\n");
                break;
    }
    return x;
}

//ask user for bet and check for errors and output the value
int bet(int ca, char bamount[]){
    int i, check, number, y;
    fflush(stdin);
    check = 0;
    number = 0;
    while(check == 0){
        printf("Place bet: ");
        for(i = 0; scanf("%c", &bamount[i]) != 0; i++){
            if((isdigit(bamount[i]) != 0) && bamount[i] >= 0){
                number++;
                check = 1;
            }
            else if(bamount[i] == '\n'){
                check = 1;
                break;
            }
            else{
                printf("\nInvalid entry, try again.\n");
                fflush(stdin);
                check = 0;
                number = 0;
                break;
            }
        }
        //convert array from type char to type int
        if(number == 1){
            y = ((int)bamount[0] - 48);
            if(y > ca){
                printf("\nInvalid entry, try again.\n");
                fflush(stdin);
                check = 0;
                number = 0;
            }
        }
        else if(number == 2){
            y = (((int)bamount[0] - 48) * 10) + ((int)bamount[1] - 48);
            if(y > ca){
                printf("\nInvalid entry, try again.\n");
                fflush(stdin);
                check = 0;
                number = 0;
            }
        }
        else{
            y = (((int)bamount[0] - 48) * 100) + (((int)bamount[1] - 48) * 10) + ((int)bamount[2] - 48);
            if(y > ca){
                printf("\nInvalid entry, try again.\n");
                fflush(stdin);
                check = 0;
                number = 0;
            }
        }
    }


    return y;
}

//roll random numbers for user and computer and adjust credits according to roll
int compare(int cnum, int bnum){
    int i, unum, pnum, temp;
    srand(time(NULL));
    for(i = 0; i < 2; i++){
            temp = rand() % 6 + 1;
        if(i == 0){
            unum = temp;
        }
        if(i == 1){
            pnum = temp;
        }
    }
    printf("\nUser number: %d\n", unum);
    printf("Computer number: %d\n\n", pnum);
    if(unum > pnum){
        printf("You won!\n");
        cnum = cnum + bnum;
    }
    else if(unum < pnum){
        printf("You lost :(\n");
        cnum = cnum - bnum;
    }
    else{
        printf("Tie - Keep credits\n");
    }
    printf("Credits remaining: %d\n", cnum);

    return cnum;
}
