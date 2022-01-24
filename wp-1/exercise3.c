// (C) Maryam Esmaeili Darestani, Lucas Nordgren, Hannah Shiels
// Work package 1: Group 6
// Exercise 3: Guess the number game
// Submission code: XXXXXX

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
/*


You  should  develop  a  very  simple  game  in  which  the  computer  creates  a  random  integer  number,  between 
1..100, and the user then tries to guess the number. The program should work as specified below: 
- The computer creates a random number 
- The user guesses the number  
- The computer responds by printing one of the following:  
• You have guessed AA times and your guess is correct (if the user guesses correctly)  
• Your guess is too low or too high, depending on the mistake of the user 
- If wrong the user is asked for a new guess, this will continue until the guess is right or the number of 
guesses exceeds the value MAX_NUMBER. 
- After end of one round the user is asked for a new round or to finish. 
The program should only except guessed numbers in the range of 1 ...100.   
An option, but not a demand, is to secure that the program does not fail (crashes) if a user by accident inputs a 
number outside of the range or a character/string.

*/


const int MIN = 1;
const int MAX = 100;
const int MAX_NUMBER = 3;

int createRandomNumber(){
    srand(time(0));
    return (rand() % (MAX - MIN + 1)) + MIN;
}

void main(){
    int randomNum = createRandomNumber();
    printf("Randomly generated number is %d", randomNum);
    int guess;
    int guessCount = 0;
    int cont = 0;
    while(cont != 1){
    printf("\nGuess between %d and %d. \n", MIN, MAX);
    scanf("%d", &guess);
    if(guess == randomNum){
        guessCount++;
        printf("\nYou have guessed %d time(s) and your guess is correct", guessCount);
        printf("\nType 1 to play another round. \n");
        int num;
        scanf("%d", &num);
        if(num == 1){
            printf("\nContinuing. New number generated. \n");
            randomNum = createRandomNumber();
            printf("Randomly generated number is %d", randomNum);
            guessCount = 0;
        } else {
            printf("Exiting...");
            cont = 1;
        }
    } else  if(guess < MIN || guess > MAX){
      printf("\nEnter a number within range. \n");
    } else if(guess < randomNum){
        printf("\nYour guess is TOO LOW \n");
        guessCount++;
    } else if(guess > randomNum){
        printf("\nYour guess is TOO HIGH \n");
        guessCount++;
    }
    if(guessCount == MAX_NUMBER){
        printf("Too many failed guesses. Exiting...");
        cont = 1;
    }
    }
}


