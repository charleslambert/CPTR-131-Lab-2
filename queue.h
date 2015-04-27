//I followed a tutorial to understand and write this code.
//The tutorial was made by Zed Shaw.

#include <stdio.h>
#include <stdlib.h>

#define EMPTY NULL


typedef struct q_node {
	struct q_node *next;
	struct q_node *prev;
	int pid;
}Q_NODE;

typedef struct queue {
	int count;
	Q_NODE *first;
	Q_NODE *last;
}QUEUE;

//create a queue
QUEUE *create();

//delete a PID in the queue
void delete();

//Put a PID in the queue
//push
void enqueue(QUEUE *queue, int value);

//Take a value out of the queue
//delete reference in the queue
//pop
int dequeue(QUEUE *queue);

//See a value in the queue
void peek();