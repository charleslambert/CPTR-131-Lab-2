#include "double_link_list.h"
#include <assert.h>
#include <string.h>

void test_insert_before();

int main() {

	test_insert_before();

	return 0;
}

void test_insert_before() {
	int a = 5;
	int b = 10;
	NODE *t_list = make_node();
	t_list->value = a;

	printf("Test insert_before\n\n");

	printf("Test 1\n");
	insert_before(t_list, b);
	assert((int) t_list->prev->value == 10);

	printf("Tests Passed\n\n");
}

void test_insert_after() {

	int a = 5;
	int b = 10;
	NODE *t_list = make_node();
	t_list->value = a;

	printf("Test insert_after\n\n");

	printf("Test 1\n");
	insert_before(t_list, b);
	assert((int) t_list->prev->value == 10);
}