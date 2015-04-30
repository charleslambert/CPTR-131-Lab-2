#include "scheduler.h"

int main() {

	char input_op;
	int input_arg;
	QUEUE *ready_queue = create();
	QUEUE *wait_queue = create();
	NODE *i_o_waitlist;

	while(input_op != 'E') {
		
		scanf("%c %d", &input_op, &input_arg||NULL); 

		switch(input_op) {

			case 'A':
				enqueue(ready_queue, input_arg);
				break;
			case 'T':
				break;
			case 'S':
				break;
			case 'I':
				break;
			case 'W':
				break;
			case 'K':
				break;
		}

	}

	printf("%d", (int)ready_queue->first->value);

	return 0;
}