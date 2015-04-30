#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "queue.h"

void test_enqueue();
void test_dequeue();

int main() {
	test_enqueue();
	test_dequeue();

	return 0;
}

void test_enqueue() {
	int a = 10;
	int b = 20;
	int c = 25;
	QUEUE *test_L = create();

	printf("Test enqueue\n\n");
	
	printf("Test 1\n");
	enqueue(test_L, a);
	assert((int)test_L->last->value == 10);
	assert((int)test_L->first->value == 10);
	assert(test_L->count == 1);

	printf("Test 2\n");
	enqueue(test_L, b);
	assert((int)test_L->last->value == 20);
	assert((int)test_L->first->value == 10);
	assert(test_L->count == 2);

	printf("Test 3\n");
	enqueue(test_L, c);
	assert((int)test_L->last->value == 25);
	assert((int)test_L->first->value == 10);
	assert(test_L->count == 3);

	printf("Tests Passed\n\n");
}


void test_dequeue() {
	QUEUE *test_L = create();
	int a = 10;
	int b = 20;

	printf("Test dequeue\n\n");

	printf("Test 1\n");
	assert(dequeue(test_L) == -1);
	assert((int)test_L->count == 0);

	printf("Test 2\n");
	enqueue(test_L, a);
	assert(dequeue(test_L) == 10);
	assert(test_L->last == EMPTY);
	assert(test_L->first == EMPTY);
	assert(test_L->count == 0);

	printf("Test 3\n");
	enqueue(test_L, a);
	enqueue(test_L, b);
	assert(dequeue(test_L) == 10);
	assert((int)test_L->first->value == 20);
	assert(test_L->count == 1);

	printf("Test Passed\n\n");
}