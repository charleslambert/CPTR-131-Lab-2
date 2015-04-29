#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "queue.h"

void test_push();
void test_pop();

int main() {
	test_push();
	test_pop();

	return 0;
}

void test_push() {
	int a = 10;
	int b = 20;
	int c = 25;
	QUEUE *test_L = create();

	printf("Test push\n\n");
	
	printf("Test 1\n");
	push(test_L, a);
	assert((*(int*)test_L->first->value) == 10);
	assert(*(int*)test_L->last->value == 10);
	assert((int)test_L->count == 1);

	printf("Test 2\n");
	push(test_L, b);
	printf("%d\n", *(int*)test_L->last->value);
	assert(*(int*)test_L->last->value == 20);
	printf("%d\n",*(int*)test_L->last->value );
	assert(*(int*)test_L->first->value == 10);
	assert(*(int*)test_L->count == 2);

	printf("Test 3\n");
	push(test_L, c);
	assert((int)test_L->first->value == 25);
	assert((int)test_L->last->value == 10);
	assert((int)test_L->count == 3);

	printf("Tests Passed\n\n");
}


void test_pop() {
	QUEUE *test_L = create();
	int a = 10;
	int b = 20;

	printf("Test pop\n\n");

	printf("Test 1\n");
	assert(pop(test_L) == -1);
	assert((int)test_L->count == 0);

	printf("Test 2\n");
	push(test_L, a);
	assert(pop(test_L) == 10);
	assert(test_L->last == EMPTY);
	assert(test_L->first == EMPTY);
	assert(test_L->count == 0);

	printf("Test 3\n");
	push(test_L, a);
	push(test_L, b);
	assert(pop(test_L) == 10);
	assert((int)test_L->first->value == 20);
	assert(test_L->count == 1);

	printf("Test Passed\n\n");
}