#include "queue.h"

QUEUE *create() {
	return calloc(1,sizeof(QUEUE));
}

//values are enqueueed into the last of the QUEUE.
//next is heading toward the first of the QUEUE.
void enqueue(QUEUE *queue, int pid) {

	//adds pid into an empty QUEUE.
	if(queue->last == EMPTY && queue->first == EMPTY) {
		NODE *node = make_node();
		node->value = pid;
		queue->first = node;
		queue->last = node;
	}
	//adds pid to a non-empty queue.
	else {
		NODE *node;

		insert_before(queue->last, pid);
		queue->last = queue->last->prev;
	}

	queue->count++;
}

//values are dequeueed off the first of the QUEUE.
//prev is heading toward the last of the QUEUE.
int dequeue(QUEUE *queue) {
	int pid;

	//returns an error if the QUEUE is empty and you try to dequeue off of it.
	if(queue->last == EMPTY && queue->first == EMPTY) {
		printf("ERROR: The queue is empty\n");
		return -1;
	}
	//if the QUEUE only has one entry dequeues it then sets the QUEUE to be empty.
	else if(queue->last == queue->first)
	{
		pid = (int) queue->first->value;
		free(queue->first);
		queue->first = EMPTY;
		queue->last = EMPTY;
	}
	//dequeues off the last thing in a QUEUE that is longer than 1.
	else {
		pid = (int) queue->first->value;
		printf("herp");
		queue->first = queue->first->prev;
		printf("derp");
		delete_node(queue->first->next);
	}

	queue->count--;
	return pid;
}

void destroy(QUEUE *queue) {
	if (queue->first == EMPTY && queue->last == EMPTY) {
		free(queue);
	}
	else {
		while (queue->count >= 0) {
			dequeue(queue);

			queue->count--;
		}
	}
}

void retrieve(int pid, QUEUE *queue) {
	NODE *node= queue->first;

	while(pid != (int) node->value) {
		node = node->prev;	
	}
}