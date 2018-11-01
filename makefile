CFLAGS = -O
CC = g++

driver: driver.o
	$(CC) $(CFLAGS) -o driver driver.o pca.o --std=c++11

driver.o: pca.o driver.cpp
	$(CC) $(CFLAGS) -c driver.cpp --std=c++11

pca.o: pca.h pca.cpp
	$(CC) $(CFLAGS) -c pca.cpp --std=c++11

run:
	./driver

clean:
	rm -f core *.o
