#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include "queue.h"
#include <unistd.h>


int stop();

void ready(int pid, QUEUE *ready_queue);

void sleep_(int pid, int abs_time);

void awaken(int pid);

void block(int pid);

int run_next();

void i_mode();

void f_mode();

void schedule_switch(char input_op, int input_arg);