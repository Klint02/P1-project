CFLAGS = -Wall -pedantic -ansi
TARGET = dijkstra.out

$(TARGET): matrixShifter.o dijkstra.c
	gcc matrixShifter.o dijkstra.c -o $(TARGET)

matrixShifter.o: matrixShifter.c matrixShifter.h
	gcc -c matrixShifter.c 

clean: 
	rm *.o *.out
