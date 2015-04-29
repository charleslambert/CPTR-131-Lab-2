#include "scheduler.h"

int stop() {

}

void ready(int pid, QUEUE *ready_queue) {
	push(ready_queue,pid);
}