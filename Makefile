all: main.o scheduler.o queue.o double_link_list.o
	$(CC) -o main main.o scheduler.o queue.o double_link_list.o

run:
	./main

clean:
	rm -f main *.o

test: test_queue.o queue.o test_scheduler.o scheduler.o test_double_link_list.o double_link_list.o
	$(CC) -o test test_queue.o queue.o test_scheduler.o scheduler.o double_link_list.o
	$(CC) -o test2 test_double_link_list.o double_link_list.o
	./test
	./test2
	rm -f test
	rm -f test2