#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include "queue.h"


int stop();

void ready(int pid, QUEUE *ready_queue);

void sleep(int pid);

void awaken(int pid);

void block(int pid);

int run_next();