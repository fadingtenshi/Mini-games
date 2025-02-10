
#define START_SCREEN_HEIGHT 7
#define START_SCREEN_WIDTH 80
#define HELLO_WORD_LEN 42
#define SELECT_WORD_LEN 60

#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <time.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>

enum Constants{

    ROCK = 1,
    PAPER,
    SCISSORS

};

const char *ConstantsName[] = {

    "Undefined",
    "rock",
    "paper",
    "scissors"

};

const int MATRIX[3][3] = {
    {-1, 0, 1},
    {1, -1, 0},
    {0, 1, -1}
};


#define PRINT_EMPTY_STR for(size_t i = 0; i < START_SCREEN_WIDTH; i++)\
    { i == 0 || i == START_SCREEN_WIDTH - 1 ? printf("%s", "#") : printf("%s", " "); } printf("\n");

#define PRINT_HASHTAG_LINE for(size_t i = 0; i < START_SCREEN_WIDTH; i++)\
    { printf("%s", "#"); } printf("\n");

#define PRINT_WELCOME_SCREEN(input, w_len) PRINT_HASHTAG_LINE; PRINT_EMPTY_STR; PRINT_EMPTY_STR;\
    printf("%s", "#"); for(size_t i = 0; i < START_SCREEN_WIDTH - 2; i++){\
    if(i < (START_SCREEN_WIDTH - 2 - w_len) / 2 ||\
    i >= START_SCREEN_WIDTH - 2 - (START_SCREEN_WIDTH - 2 - w_len) / 2) { printf("%s", " "); }\
    else{printf("%s", input); i = i + w_len - 1;}}\
    printf("%s\n", "#"); PRINT_EMPTY_STR; PRINT_EMPTY_STR;


void printTextLine(const char* input){

    printf("%s", "#");

    uint8_t offset = 0;
    size_t w_len = strlen(input);
    if (w_len % 2 != 0) offset++;

    for(size_t i = 0; i < START_SCREEN_WIDTH - 2; i++){ 
        
        if(i < (START_SCREEN_WIDTH - 2 - w_len) / 2 + offset ||
        i >= START_SCREEN_WIDTH - 2 - (START_SCREEN_WIDTH - 2 - w_len) / 2) { printf("%s", " "); }
        else{printf("%s", input); i = i + w_len - 1;}
    
    }
    printf("%s\n", "#");

}

void printGameInterface(uint8_t tool, uint8_t random_choice){

    char player_choice[25];
    snprintf(player_choice, sizeof(player_choice), "Your choice: %s", ConstantsName[tool]);

    char bot_choice[25];
    snprintf(bot_choice, sizeof(bot_choice), "Enemy's choice: %s", ConstantsName[random_choice]);

    PRINT_HASHTAG_LINE;
    PRINT_EMPTY_STR;

    printTextLine(player_choice);
    if(random_choice != 0){

        int8_t result = MATRIX[--tool][--random_choice];

        printTextLine(bot_choice);

        if (result == 0) { printTextLine("You're lose..."); }
        else if (result == 1) { printTextLine("You're Win!!! Gratz"); }
        else { printTextLine("Draw!"); }         

        PRINT_EMPTY_STR;

    }
    else{

        PRINT_EMPTY_STR;
        PRINT_EMPTY_STR;

    }
}

int main() {

    uint8_t randBotChoice;
    PRINT_WELCOME_SCREEN("Welcome to the Rock, Paper, Scissors game!", HELLO_WORD_LEN);
    srand(time(NULL));

    while(true){
        
        PRINT_WELCOME_SCREEN("Please, select your tool (1 - Rock; 2 - Paper; 3 - Scissors)", SELECT_WORD_LEN);

        uint8_t choice;

        for(size_t i = 0; i < (START_SCREEN_WIDTH - 2) / 2; i++){ printf("%s", " "); }
        scanf("%hhd", &choice);

        randBotChoice = (int)(1.0 + 3.0 * rand() / RAND_MAX);

        printGameInterface(choice, randBotChoice);

    }

    return 0;

}