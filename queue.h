//I followed a tutorial to understand and write this code.
//The tutorial was made by Zed Shaw.

#include <stdio.h>
#include <stdlib.h>
#include "double_link_list.h"

#define EMPTY NULL

typedef struct queue {
	int count;
	NODE *first;
	NODE *last;
}QUEUE;

//create a QUEUE
QUEUE *create();

//delete a PID in the QUEUE
void delete();

//Put a PID in the QUEUE
//push
void push(QUEUE *queue, int value);

//Take a value out of the QUEUE
//delete reference in the QUEUE
//pop
int pop(QUEUE *queue);

//See a value in the QUEUE, at tail
void peek();

//Destroy QUEUE
void destroy(QUEUE *queue);