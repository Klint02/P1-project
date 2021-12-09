CFLAGS = -Wall -pedantic
TARGET = trashRoutePlanner.out

$(TARGET): matrixShifter.o dijkstra.o debug.o trashRoutePlanner.c
	gcc $(CFLAGS) matrixShifter.o debug.o dijkstra.o trashRoutePlanner.c -o $(TARGET)

dijkstra.o: dijkstra.c trashLib.h
	gcc -c $(CFLAGS) dijkstra.c 

matrixShifter.o: matrixShifter.c trashLib.h
	gcc -c $(CFLAGS) matrixShifter.c 

debug.o: debug.c trashLib.h
	gcc -c $(CFLAGS) debug.c 

clean: 
	rm -rf *.o *.out .vscode 
