# Maze solving Simulation with C
## [Check this amazing simulator with simple API](https://github.com/mackorone/mms-c)
### In floodfill implementation:
#### 1- Comment this part of code (We will use it later):
```c
    loadArrayFromFile(distArr, "dist.bin");
    loadCharArrayFromFile(wallsArr, "walls.bin");

    for (int i = 0; i < MAZE_SIZE; i++) {
    for (int j = 0; j < MAZE_SIZE; j++) {
           maze[i][j].distance = distArr[i][j];
       }
    }
    for (int i = 0; i < MAZE_SIZE; i++) {
    for (int j = 0; j < MAZE_SIZE; j++) {
           maze[i][j].walls = wallsArr[i][j];
       }
    }
```
#### 2- Build the code in simulator then click run (Getting to know the maze)
#### 3- Binary files dist.bin contains shortest distances to goal and walls.bin contains the walls of the maze (maze is now recognized)
#### 4- Comment this part of code (Uncomment the code in step 1 so we can use it):
```c
    for (int i = 0; i < MAZE_SIZE; i++) {
    for (int j = 0; j < MAZE_SIZE; j++) {
            distArr[i][j] = maze[i][j].distance;
        }
    }
    for (int i = 0; i < MAZE_SIZE; i++) {
    for (int j = 0; j < MAZE_SIZE; j++) {
            wallsArr[i][j] = maze[i][j].walls;
       }
    }
    saveArrayToFile(distArr, "dist.bin");
    saveCharArrayToFile(wallsArr, "walls.bin");
```
#### 5- Build the code in simulator then click run and let the magic of the algorithm amaze you
