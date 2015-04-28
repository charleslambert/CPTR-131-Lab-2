#include "scheduler.h"

int stop() {

}

void ready(int pid, LIST *ready_queue) {
	push(ready_queue,pid);
}