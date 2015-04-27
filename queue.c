#include "queue.h"

QUEUE *create() {
	return calloc(1,sizeof(QUEUE));
}

//values are pushed into the first of the queue.
//next is heading toward the first of the queue.
void enqueue(QUEUE *queue, int value) {
	Q_NODE *node = calloc(1, sizeof(Q_NODE));
	
	node->pid = value;

	//adds pid into an empty list.
	if(queue->last == EMPTY && queue->first == EMPTY) {
		queue->first = node;
		queue->last = node;
	}
	//adds pid to a non-empty list.
	else {
		queue->first->next = node;
		node->prev = queue->first;
		queue->first = node;
	}

	queue->count++;
}

//values are poped off the tail of the queue.
//prev is heading toward the last of the queue.
int dequeue(QUEUE *queue) {
	int pid;

	//returns an error if the queue is empty and you try to pop off of it.
	if(queue->last == EMPTY && queue->first == EMPTY) {
		printf("ERROR: The queue is empty\n");
		return -1;
	}
	//if the queue only has one entry pops it then sets the queue to be empty.
	else if(queue->last == queue->first)
	{
		pid = queue->last->pid;
		free(queue->last);
		queue->first = EMPTY;
		queue->last = EMPTY;
	}
	//pops off the last thing in a queue that is longer than 1.
	else {
		pid = queue->last->pid;
		queue->last = queue->last->next;
		free(queue->last->prev);
		queue->last->prev = EMPTY;
	}

	queue->count--;
	return pid;
}

