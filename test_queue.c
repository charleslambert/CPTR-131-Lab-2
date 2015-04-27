#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "queue.h"

void test_enqueue();
void test_dequeue();

int main() {
	test_enqueue();
	test_dequeue

	return 0;
}

void test_enqueue() {
	int a = 10;
	int b = 20;
	int c = 25;
	QUEUE *test_q = create();

	printf("Test enqueue\n\n");
	
	printf("Test 1\n");
	enqueue(test_q, a);
	assert(test_q->first->pid=10);
	assert(test_q->last->pid=10);

	printf("Test 2\n");
	enqueue(test_q, a);
	assert(test_q->first->pid=20);
	assert(test_q->last->pid=10);

	printf("Test 3\n");
	enqueue(test_q, a);
	assert(test_q->first->pid=25);
	assert(test_q->last->pid=10);

	printf("Tests Passed\n\n");
}


void test_dequeue() {
	QUEUE *test_q = create();
	int a = 10;
	int b = 20;

	printf("Test 1\n");
	assert(dequeue(test_q)==-1);

	printf("Test 2\n");
	enqueue(test_q, a);
	assert(dequeue(test_q)==10);

	printf("Test 3\n");
	enqueue(test_q, a);
	enqueue(test_q, b);
	assert(dequeue(test_q)==20);
}