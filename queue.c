#include "queue.h"

QUEUE *create() {
	return calloc(1,sizeof(QUEUE));
}

//values are pushed into the first of the QUEUE.
//next is heading toward the first of the QUEUE.
void push(QUEUE *queue, int pid) {

	//adds pid into an empty QUEUE.
	if(queue->last == EMPTY && queue->first == EMPTY) {
		NODE *node = make_node();
		node->value = &pid;
		queue->first = node;
		queue->last = node;
	}
	//adds pid to a non-empty queue.
	else {
		insert_before(queue->last, &pid);
		queue->last = queue->last->prev;
		/*queue->first->next = node;
		node->prev = queue->first;
		queue->first = node;*/
	}

	queue->count++;
}

//values are poped off the tail of the QUEUE.
//prev is heading toward the last of the QUEUE.
int pop(QUEUE *queue) {
	int pid;

	//returns an error if the QUEUE is empty and you try to pop off of it.
	if(queue->last == EMPTY && queue->first == EMPTY) {
		printf("ERROR: The queue is empty\n");
		return -1;
	}
	//if the QUEUE only has one entry pops it then sets the QUEUE to be empty.
	else if(queue->last == queue->first)
	{
		pid = (int) queue->last->value;
		free(queue->last);
		queue->first = EMPTY;
		queue->last = EMPTY;
	}
	//pops off the last thing in a QUEUE that is longer than 1.
	else {
		pid = (int) queue->last->value;
		queue->last = queue->last->next;
		free(queue->last->prev);
		queue->last->prev = EMPTY;
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
			pop(queue);

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