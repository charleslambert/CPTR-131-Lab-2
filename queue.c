#include "queue.h"

QUEUE *create() {
	return calloc(1,sizeof(QUEUE));
}

//values are pushed into the head of the list.
void enqueue(QUEUE *queue, int value) {
	Q_NODE *node = calloc(1, sizeof(Q_NODE));
	
	node->pid = value;

	if(queue->last == EMPTY) {
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

}
