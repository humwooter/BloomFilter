PA1: main.o LinkedList.o BloomFilter.o HashTable.o sharedFuncts.o 
	g++ $^ -Werror -o $@

clean:
	rm -f *.o *.exe
