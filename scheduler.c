#include "scheduler.h"

int stop(int current_process) {	
	if (current_process == NULL) {
		return 0;
	}
	return current_process;
}

void ready(int pid, QUEUE *ready_queue) {
	enqueue(ready_queue, pid);
}

void sleep_(int pid, int abs_time) {

}

void awaken(int pid) {

}

void block(int pid) {

}

int run_next() {

}

void i_mode() {
	char input_op;
	int input_arg;
	char input[64];

	while(input_op != 'E') {
		
		scanf("%s", input);

		if(input[0] == 'A' || input[0] == 'I' || input[0] == 'W' || input[0] == 'K') {
			sscanf(input,"%c %d", &input_op, &input_arg); 
		}
		else {
			sscanf(input, "%c", &input_op);
		}

		schedule_switch(input_op, input_arg);
	}
}

void f_mode() {
	char input_op;
	int input_arg;
	char input[64];
	FILE *file;
	char file_name[64];


	printf("\nFile to be used?: ");
	scanf("%s", file_name);

	if(access(file_name,F_OK) == -1) {
		printf("File does not exit\n");
		exit(1);
	}

	file = fopen(file_name, "r");

	while(fgets(input, 64,file) != NULL) {

		if(input[0] == 'A' || input[0] == 'I' || input[0] == 'W' || input[0] == 'K') {
			sscanf(input,"%c %d", &input_op, &input_arg); 
		}
		else {
			sscanf(input, "%c", &input_op);
		}

		schedule_switch(input_op,input_arg);
	}
}

void schedule_switch(char input_op, int input_arg) {
	QUEUE *ready_queue = create();
	QUEUE *wait_queue = create();
	NODE *i_o_waitlist = make_node();
	int clock_count = 0;
	int running_process;

	switch(input_op) {

		case 'A':
			enqueue(ready_queue, input_arg);
			break;
		case 'T':
			enqueue(ready_queue, running_process);
			clock_count += 1;
			//check timed wait queue for process, if process ready put in ready queue
			running_process = dequeue(ready_queue);
			break;
		case 'S':
			break;
		case 'I':
			break;
		case 'W':
			break;
		case 'K':
			retrieve(input_arg, ready_queue->first);
			retrieve(input_arg, wait_queue->first);
			retrieve(input_arg, i_o_waitlist);
			break;
	}
}