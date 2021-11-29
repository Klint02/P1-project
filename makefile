CFLAGS = -Wall -pedantic -ansi
TARGET = trashRoutePlanner.out

$(TARGET): matrixShifter.o dijkstra.o trashRoutePlanner.c
	gcc matrixShifter.o dijkstra.o trashRoutePlanner.c -o $(TARGET)

dijkstra.o: dijkstra.c trashLib.h
	gcc -c dijkstra.c 

matrixShifter.o: matrixShifter.c trashLib.h
	gcc -c matrixShifter.c 

clean: 
	rm *.o *.out
