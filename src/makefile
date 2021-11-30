CFLAGS = -Wall -pedantic -ansi
TARGET = trashRoutePlanner.out

$(TARGET): matrixShifter.o dijkstra.o debug.o trashRoutePlanner.c
	gcc matrixShifter.o debug.o dijkstra.o trashRoutePlanner.c -o $(TARGET)

dijkstra.o: dijkstra.c trashLib.h
	gcc -c dijkstra.c 

matrixShifter.o: matrixShifter.c trashLib.h
	gcc -c matrixShifter.c 

debug.o: debug.c trashLib.h
	gcc -c debug.c 

clean: 
	rm -rf *.o *.out .vscode 
