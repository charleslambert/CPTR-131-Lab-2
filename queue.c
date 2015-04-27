#include "queue.h"

QUEUE *create() {
	return calloc(1,sizeof(QUEUE));
}

//values are pushed into the head of the list.
void enqueue(QUEUE *queue, int value) {
	Q_NODE *node = calloc(1, sizeof(Q_NODE));
	
	node->pid = value;

	if(queue->last == EMPTY && queue->first == EMPTY) {
		queue->first = node;
		queue->last = node;
	}
	else {
		queue->first->next = node;
		node->prev = queue->first;
		queue->first = node;
	}

	queue->count++;
}

int dequeue(QUEUE *queue) {
	int pid;


	if(queue->last == EMPTY && queue->first == EMPTY) {
		printf("The queue is empty\n");
		return -1;
	}
	else if(queue->last == queue->first)
	{
		pid = queue->last->pid;
		free(queue->first);
		queue->first = EMPTY;
		queue->last = EMPTY;
	}
	else {
		pid = queue->last->pid;
		queue->last = queue->last->next;
		free(queue->last->prev);
		queue->last->prev = EMPTY;
	}

	return pid;
}
