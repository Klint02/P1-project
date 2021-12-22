# P1-project

Nicklas | Patrick | Daniel | Peter | Rasmus | Mohammed
:------:|:-------:|:------:|:-----:|:------:|:--------:
![Nicklas](https://avatars2.githubusercontent.com/u/44356711?s=64&v=64)|![Patrick](https://avatars0.githubusercontent.com/u/44425816?s=64&v=64)|![Daniel](https://avatars.githubusercontent.com/u/10807534?s=64&v=64)|![Peter](https://avatars.githubusercontent.com/u/93643193?v=64&s=64)|![Rasmus](https://avatars.githubusercontent.com/u/93643276?s=64&v=64)|![Mohammed](https://avatars.githubusercontent.com/u/93643200?s=64&v=64)|
Eripyo|Mr. Frog|Linuk|Ishøj|Fnuller|Mæhmed|

`ROUTEPLANNER` lets you easily find the best route to collect your trash

![Shallow Backup GIF Demo](https://media2.giphy.com/media/QNFhOolVeCzPQ2Mx85/giphy.gif?cid=790b7611e9129f4e085c46b1d291a1be70123910d3e4fbf2&rid=giphy.gif&ct=g)

### Contents
---

 * [Why?](#why)
 * [Installation](#installation)
 * [Usage](#usage)
 * [Thank you for reading](#Thanks)

### Why?
---

This is a univeristy project for solving inceffecient garbage collection:

+ it is good
+ it is fast
+ it is easy
+ yes
+ profit?

### Installation
---

1. Download with (https://github.com/Klint02/P1-project/releases)
    + `Download`

2. Install
    To compile the code on a Windows system , use the following commands in your terminal while in the /src directory.

gcc -c -Wall -pedantic debug.c

gcc -c -Wall -pedantic matrixShifter.c

gcc -c -Wall -pedantic dijkstra.c

gcc matrixShifter.o debug.o dijkstra.o trashRoutePlanner.c -o trashRoutePlanner.exe

To compile the code on a Linux system use the following command while in the /src directory. 

make

After compiling the code, input your adjacency matrix in the "matrixData.txt" located in the /src directory, and then run your executable or simply run the program with the default matrix already present in matrixData.txt. 

### Usage
---

When running the program the user will be prompted an output in the terminal, which firstly specifies the trash compactness in each node, and then how full the truck currently is. When running this data-set the nodes with their correct order in reference to the shortest path is then specified while reminding the user about the trucks fullness and the trash compactness for each node in their order from 0 to 10. The user can with this information then see that the current node has been emptied. At last the user will be shown the final calculated path and the distance it took to reach it. Each node that is emptied fills the truck 1/4 of it's full capacity, meaning that the calculated path will only be taking the 4 closest trash nodes before returning home to the base node, where the truck returns home after node 8 due to the truck running out of capacity. The truck will then calculate the route to the last possible nodes and thereby finish its purpose of collecting the trash. One should note that the starting node is represented as the base of the truck and is thereforee not supposed to have a trash compactness parameter. 


### Thanks 
---

Many thanks for reading ❤️
![wide](https://pbs.twimg.com/media/D5prppPUcAEhUFo.jpg)
