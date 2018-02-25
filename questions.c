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
#include <stdint.h>
#include "questions.h"
#define SIZE 10
// Initializes the array of questions for the game
void initialize_game(void)
{
    // initialize each question struct and assign it to the questions array
    question question1 = 
    {
        .category = (uintptr_t)categories[0], .question = "T/F: Java is the same as Javascript.", .answer = "F", .value = 100, .answered = false
    };
    questions[0] = question1;

    question question2 = 
    {
        .category = (uintptr_t)categories[0], .question = "T/F: The | Operator is used to pipe input/output.", .answer = "F", .value = 200, .answered = false
    };
    questions[1] = question2;

    question question3 = 
    {
        .category = (uintptr_t)categories[0], .question = "T/F: STR R2, R3 will store contents of R3 into R2.", .answer = "F", .value = 300, .answered = false
    };
    questions[2] = question3;

    question question4 = 
    {
        .category = (uintptr_t)categories[0], .question = "T/F: The PC in each thread is different.", .answer = "T", .value = 400, .answered = false
    };
    questions[3] = question4;

    question question5 = 
    {
        .category = (uintptr_t)categories[1], .question = "T/F: A binary search runs in O(logn).", .answer = "T", .value = 100, .answered = false
    };
    questions[4] = question5;

    question question6 = 
    {
        .category = (uintptr_t)categories[2], .question = "T/F: A worst case scenario for algorithms are lower bounds.", .answer = "F", .value = 200, .answered = false
    };
    questions[5] = question6;

    question question7 = 
    {
        .category = (uintptr_t)categories[1], .question = "T/F: A DFS algorithm will always find the path to a goal node.", .answer = "F", .value = 300, .answered = false
    };
    questions[6] = question7;

    question question8 = 
    {
        .category = (uintptr_t)categories[1], .question = "T/F: An A* search algorithm uses heuristics and best first search together.", .answer = "T", .value = 400, .answered = false
    };
    questions[7] = question8;

    question question9 = 
    {
        .category = (uintptr_t)categories[2], .question = "T/F: You only need one semi-colon in a SQL statement.", .answer = "T", .value = 100, .answered = false
    };
    questions[8] = question9;

    question question10 = 
    {
        .category = (uintptr_t)categories[2], .question = "T/F: A Foreign Key doesn't not need to be a Primary Key in another table.", .answer = "F", .value = 200, .answered = false
    };
    questions[9] = question10;

    question question11 = 
    {
        .category = (uintptr_t)categories[2], .question = "T/F: NOT IN and NOT EXISTS are exactly the same, and return the same query.", .answer = "F", .value = 300, .answered = false
    };
    questions[10] = question11;

    question question12 = 
    {
        .category = (uintptr_t)categories[2], .question = "T/F: SELECT AVG(prices) FROM store WHERE prices <= 0; will return average price of all free items.", .answer = "T", .value = 400, .answered = false
    };
    questions[11] = question12;

    
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
    printf("Category: %s, Value: %d", category, value);
}

// Returns true if the answer is correct for the question for that category and dollar value
bool valid_answer(char *category, int value, char *answer)
{
    // Look into string comparison functions
    for (int i = 0; i < NUM_QUESTIONS; i ++)
    {
        bool validC = strcmp (questions[i].category, category);
        bool validA = strcmp (questions[i].answer, answer);
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
    // lookup the question and see if it's already been marked as answered
    for (int i = 0; i < NUM_QUESTIONS; i ++)
    {
        bool validC = strcmp (questions[i].category, category);
        if (validC == true && questions[i].answered == true && value == questions[i].value)
        {
            return true;
        }
    }
    return false;
}
