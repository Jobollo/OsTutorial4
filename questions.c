/*
 * Tutorial 4 Jeopardy Project for SOFE 3950U Operating Systems
 *
 * Copyright (C) 2018, <GROUP MEMBERS>
 * All rights reserved.
 *
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include "questions.h"
#define SIZE 10
// Initializes the array of questions for the game
void initialize_game(void)
{
    
	strcpy(questions[0].category, "programming");
	strcpy(questions[0].question, "_______ is related to Java as a car is related to a carpet");
	strcpy(questions[0].answer, "javascript");
	questions[0].value = 100;
	questions[0].answered = false;

	strcpy(questions[1].category, "programming");
	strcpy(questions[1].question, "The symbol | is used to ______ input/output");
	strcpy(questions[1].answer, "pipe");
	questions[1].value = 200;
	questions[1].answered = false;

	strcpy(questions[2].category, "programming");
	strcpy(questions[2].question, "In Assembly STR R2, R3 will ____ contents of R3 into R2");
	strcpy(questions[2].answer, "store");
	questions[2].value = 300;
	questions[2].answered = false;

	strcpy(questions[3].category, "programming");
	strcpy(questions[3].question, "The __ in each thread is different");
	strcpy(questions[3].answer, "PC");
	questions[3].value = 400;
	questions[3].answered = false;




	strcpy(questions[4].category, "algorithms");
	strcpy(questions[4].question, "This popular search algorithm is also known as half-interval search");
	strcpy(questions[4].answer, "binarysearch");
	questions[4].value = 100;
	questions[4].answered = false;

	strcpy(questions[5].category, "algorithms");
	strcpy(questions[5].question, "The worst-case scenario for algorithms are _____ bound");
	strcpy(questions[5].answer, "lower");
	questions[5].value = 200;
	questions[5].answered = false;

	strcpy(questions[6].category, "algorithms");
	strcpy(questions[6].question, "This common search algorithm doe not always find a path to a node");
	strcpy(questions[6].answer, "DFS");
	questions[6].value = 300;
	questions[6].answered = false;

	strcpy(questions[7].category, "algorithms");
	strcpy(questions[7].question, "This search algorithm uses both best-first and lowest-cost-first");
	strcpy(questions[7].answer, "A*");
	questions[7].value = 400;
	questions[7].answered = false;




	strcpy(questions[8].category, "database");
	strcpy(questions[8].question, "Only one semi-colon is needed for an ___ statement");
	strcpy(questions[8].answer, "SQL");
	questions[8].value = 100;
	questions[8].answered = false;

	strcpy(questions[9].category, "database");
	strcpy(questions[9].question, "This type of key needs to be a primary key in another table");
	strcpy(questions[9].answer, "foreign");
	questions[9].value = 200;
	questions[9].answered = false;

	strcpy(questions[10].category, "database");
	strcpy(questions[10].question, "Contains the smallest unit of meaningful information in a row/record");
	strcpy(questions[10].answer, "field");
	questions[10].value = 300;
	questions[10].answered = false;

	strcpy(questions[11].category, "database");
	strcpy(questions[11].question, "The subset of SQL used to select and update the data in a database");
	strcpy(questions[11].answer, "DML");
	questions[11].value = 400;
	questions[11].answered = false;

}

// Displays each of the remaining categories and question dollar values that have not been answered
void display_categories(void)
{
    char v[12][20];

	for (int i = 0; i < 12; i++) {
		
		if (questions[i].answered == false) {
			
			snprintf(v[i], 20, "%d", questions[i].value);
			
		} else {

			strcpy(v[i], "   ");

		}
			
	}

	
	printf("   %s    |   %s    |   %s   \n", categories[0], categories[1], categories[2]);
	printf("  _________________________________________________\n");

	printf("      %s         |     %s         |         %s   \n", v[0], v[1], v[2]);
	printf("  _________________________________________________\n");
	
	printf("      %s         |     %s         |         %s   \n", v[3], v[4], v[5]);
	printf("  _________________________________________________\n");
	
	printf("      %s         |     %s         |         %s   \n", v[6], v[7], v[8]);
	printf("  _________________________________________________\n");

	printf("      %s         |     %s         |         %s   \n", v[9], v[10], v[11]);
	printf("  _________________________________________________\n");
}

// Displays the question for the category and dollar value
void display_question(char *category, int value)
{
	// Look into string comparison functions
    for (int i = 0; i < NUM_QUESTIONS; i ++)
    {
        bool validC = strcmp (questions[i].category, category);
        //bool validA = strcmp (questions[i].answer, answer);
        if (validC == true && value == questions[i].value)
        {
			printf("Question: %s (%d)\n", questions[i].question, questions[i].value);
        }
    }

}

// Returns true if the answer is correct for the question for that category and dollar value
bool valid_answer(char *category, int value, char  *answer)
{
	//printf("Printing from valid_answer!\n");
    // Look into string comparison functions
	char answerC[256] = "";
	//printf(&answer);
    for (int i = 0; i < NUM_QUESTIONS; i ++)
    {
        bool validC = strcmp (questions[i].category, category);
		strcpy(answerC, answer);
        bool validA = strcmp (questions[i].answer, answerC);
        if (validC == true && value == questions[i].value && validA == true)
        {
            return true;
        }
    }
   
    return false;
}

// Returns true if the question has already been answered
bool already_answered(char *category, int value)
{
	bool answered=false;
	for (int i = 0; i < 12; i++) {
		if (questions[i].category==category && (questions[i].value == value)) {
			if (questions[i].answered == true) {
				answered = true;
			} else {
				answered = false;
			}
		}
	}
	return answered;
}

