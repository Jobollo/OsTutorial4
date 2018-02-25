/*
 * Tutorial 4 Jeopardy Project for SOFE 3950U / CSCI 3020U: Operating Systems
 *
 * Copyright (C) 2015, <GROUP MEMBERS>
 * All rights reserved.
 *
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "questions.h"
#include "players.h"
#include "jeopardy.h"

// Put macros or constants here using #define
#define BUFFER_LEN 256
#define NUM_PLAYERS 4

// Put global environment variables here

// Processes the answer from the user containing what is or who is and tokenizes it to retrieve the answer.
void tokenize(char *input);
{
	char *firstWord, *secondWord, *answer, *context;

	int inputLength = strlen(input);
	char *inputCopy = (char*) calloc(inputLength + 1, sizeof(char));
	strncpy(inputCopy, input, inputLength);

	firstWord = strtok_r (inputCopy, " ", &context);
	secondWord = strtok_r (NULL, " ", &context);
	answer = context;

	if (strcmp(firstWord, "what") == 0 || strcmp(firstWord, "who") == 0)
	{
	     if (strcmp(secondWord, "is") == 0)
	     {
		input = answer;
	     }
	}
	free(inputCopy);
}

// Displays the game results for each player, their name and final score, ranked from first to last place
void show_results(struct player *players, int num_players);

int game_state;


int main(int argc, char *argv[])
{
    // An array of 4 players, may need to be a pointer if you want it set dynamically
    struct player players[NUM_PLAYERS];

    // EXAMPLE: player 1 is named Fred
    strcpy(players[0].name, "Fred");
    printf("%s\n", players[0].name);
    
    // Buffer for user input
    char buffer[BUFFER_LEN] = { 0 };

    // Display the game introduction and initialize the questions
    initialize_game();

    // Prompt for players names
    printf("Time to start the game! Type out the names of each player.");
    // initialize each of the players in the array
    for (int i = 0; i < NUM_PLAYERS; i ++)
    {
        printf("Type in Player %d's name: ", i + 1);
        scanf("%s", players[i].name);
        players[i].score = 0;
    }

    // Perform an infinite loop getting command input from users until game ends
    game_state = 1;
    while (game_state)
    {
        // EXAMPLE: This line gets a line of input from the user
        fgets(buffer, BUFFER_LEN, stdin);
        printf("[before]%s[after]", buffer);

        // Call functions from the questions and players source files

        // Execute the game until all questions are answered

        // Display the final results and exit
    }
    return EXIT_SUCCESS;
}
