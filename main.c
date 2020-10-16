/**
 * main.c
 * Sean Cobb
 * October, 2020
 * Configure input from Ti 3x4 Keypad and print value
 */


#include "msp.h"
#include <stdio.h>


void keyInit(void);
void delay(void);
void Read_Keypad(void);
void printKey(char num);


void main(void)
{
	WDT_A->CTL = WDT_A_CTL_PW | WDT_A_CTL_HOLD;		    // stop watchdog timer

    keyInit();                                          // set up keypad GPIO

	while(1){
	    Read_Keypad();                                  // call function to read and print keypad values
	}
}



// initialize GPIO for keypad
void keyInit(void){
    P2->DIR = 0;                                        // set rows as inputs
    P5->DIR = 0;                                        // set columns as inputs
    P5->REN |= (BIT0 | BIT1 | BIT2);                    // enable resistors for columns
    P5->OUT |= (BIT0 | BIT1 | BIT2);                    // set resistors as pullups
}


// SysTick delay function
void delay(void){
    SysTick->LOAD = 3000;                               // load the value into the timer
    SysTick->VAL = 0;                                   // set the value to zero
    SysTick->CTRL = 5;                                  // enable the timer
    while(!(SysTick->CTRL & 0x10000) == 1);              // wait until flag is set
}


// function to read and print values based on what key was pressed
void Read_Keypad(void){
    int col1, col2, col3;
    char key;
    P2->DIR = 0;                                        // disable all rows
    P2->DIR |= BIT4;                                    // enable row 1
    P2->OUT &= ~BIT4;                                   // set row 1 low
    delay();                                            // wait for signal to settle
    col1 = P5->IN & BIT0;                               // read col 1, row 1
    col2 = P5->IN & BIT1;                               // read col 2, row 1
    col3 = P5->IN & BIT2;                               // read col 3, row 1
    if(col1 == 0){                                      // if column 1 is low
        key = '1';
        printKey(key);                                  // print value
        while(col1 == 0){                               // while col 1 is low
            col1 = P5->IN & BIT0;                       // read col1, row 1
            delay();                                    // wait for release
        }
    }
    else if(col2 == 0){                                 // if col 2 is low
        key = '2';
        printKey(key);                                  // print value
        while(col2 == 0){                               // while col 2 is low
            col2 = P5->IN & BIT1;                       // read col 2, row 1
            delay();                                    // wait for release
        }
    }
    else if(col3 == 0){                                 // if col 3 is low
        key = '3';
        printKey(key);                                  // print value
        while(col3 == 0){                               // while col 3 is low
            col3 = P5->IN & BIT2;                       // read col 3, row 1
            delay();                                    // wait for release
        }
    }
    P2->OUT |= BIT4;                                    // set row 1 high
    P2->DIR = 0;                                        // disable all rows


    P2->DIR |= BIT5;                                    // enable row 2
    P2->OUT &= ~BIT5;                                   // set row 2 low
    delay();                                            // wait for signal to settle
    col1 = P5->IN & BIT0;                               // read col 1, row 2
    col2 = P5->IN & BIT1;                               // read col 2, row 2
    col3 = P5->IN & BIT2;                               // read col 3, row 2
    if(col1 == 0){                                      // if col 1 is low
        key = '4';
        printKey(key);                                  // print value
        while(col1 == 0){                               // while col 1 is low
            col1 = P5->IN & BIT0;                       // read col 1, row 2
            delay();                                    // wait for release
        }
    }
    else if(col2 == 0){                                 // if col 2 is low
        key = '5';
        printKey(key);                                  // print value
        while(col2 == 0){                               // while col 2 is low
            col2 = P5->IN & BIT1;                       // read col 2, row 2
            delay();                                    // wait for release
        }
    }
    else if(col3 == 0){                                 // if col 3 is low
        key = '6';
        printKey(key);                                  // print value
        while(col3 == 0){                               // while col 3 is low
            col3 = P5->IN & BIT2;                       // read col 3, row 2
            delay();                                    // wait for release
        }
    }
    P2->OUT |= BIT5;                                    // set row 2 high
    P2->DIR = 0;                                        // disable all rows


    P2->DIR |= BIT6;                                    // enable row 3
    P2->OUT &= ~BIT6;                                   // set row 3 low
    delay();                                            // wait for signal to settle
    col1 = P5->IN & BIT0;                               // read col 1, row 3
    col2 = P5->IN & BIT1;                               // read col 2, row 3
    col3 = P5->IN & BIT2;                               // read col 3, row 3
    if(col1 == 0){                                      // if column 1 is low
        key = '7';
        printKey(key);                                  // print value
        while(col1 == 0){                               // while col 1 is low
            col1 = P5->IN & BIT0;                       // read col 1, row 3
            delay();                                    // wait for release
        }
    }
    else if(col2 == 0){                                 // if col 2 is low
        key = '8';
        printKey(key);                                  // print value
        while(col2 == 0){                               // while col 2 is low
            col2 = P5->IN & BIT1;                       // read col 2, row 3
            delay();                                    // wait for release
        }
    }
    else if(col3 == 0){                                 // if col 3 is low
        key = '9';
        printKey(key);                                  // print value
        while(col3 == 0){                               // while col 3 is low
            col3 = P5->IN & BIT2;                       // read col 3, row 3
            delay();                                    // wait for release
        }
    }
    P2->OUT |= BIT6;                                    // set row 3 high
    P2->DIR = 0;                                        // disable all rows


    P2->DIR |= BIT7;                                    // enable row 4
    P2->OUT &= ~BIT7;                                   // set row 1 low
    delay();                                            // wait for signal to settle
    col1 = P5->IN & BIT0;                               // read col 1, row 4
    col2 = P5->IN & BIT1;                               // read col 2, row 4
    col3 = P5->IN & BIT2;                               // read col 3, row 4
    if(col1 == 0){                                      // if column 1 is low
        key = '*';
        printKey(key);                                  // print value
        while(col1 == 0){                               // while col 1 is low
            col1 = P5->IN & BIT0;                       // read col 1, row 4
            delay();                                    // wait for release
        }
    }
    else if(col2 == 0){                                 // if col 2 is low
        key = '0';
        printKey(key);                                  // print value
        while(col2 == 0){                               // while col 2 is low
            col2 = P5->IN & BIT1;                       // read col 2, row 4
            delay();                                    // wait for release
        }
    }
    else if(col3 == 0){                                 // if col 3 is low
        key = '#';
        printKey(key);                                  // print value
        while(col3 == 0){                               // while col 3 is low
            col3 = P5->IN & BIT2;                       // read col 3, row 4
            delay();                                    // wait for release
        }
    }
    P2->OUT |= BIT7;                                    // set row 4 high
    P2->DIR = 0;                                        // disable all rows
}


// function to print the numerical value of the button pushed on the keypad
void printKey(char num){
    printf("Key: %c\n", num);
}
