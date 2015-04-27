all: queue.o
	$(CC) -o queue queue.o

run:
	./queue

clean:
	rm -f queue *.o

test: test_queue.o queue.o
	$(CC) -o test test_queue.o queue.o
	./test
	rm -f test