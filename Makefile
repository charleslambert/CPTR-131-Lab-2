all: main.o scheduler.o queue.o
	$(CC) -o main main.o scheduler.o queue.o

run:
	./main

clean:
	rm -f main *.o

test: test_queue.o queue.o test_scheduler.o scheduler.o
	$(CC) -o test test_queue.o queue.o test_scheduler.o scheduler.o
	./test
	rm -f test