#include "scheduler.h"

int stop() {

}

void ready(int pid, QUEUE *ready_queue) {
	enqueue(ready_queue,pid);
}