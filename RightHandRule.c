#include <stdio.h>
#include "API.h"

// Define directions
#define NORTH 0
#define EAST 1
#define SOUTH 2
#define WEST 3
#define MAZE_SIZE 16
#define GoalX 0
#define GoalY 8

// Current state of the robot
int x = 0, y = 0;           // Current position
int direction = NORTH;      // Current direction

// Log helper
void log(char* text) {
    fprintf(stderr, "%s\n", text);
    fflush(stderr);
}

// Update position based on direction
void updatePosition() {
    switch (direction) {
        case NORTH: y++; break;
        case EAST:  x++; break;
        case SOUTH: y--; break;
        case WEST:  x--; break;
    }
}

// Turn the robot to the left
void turnLeft() {
    API_turnLeft();
    direction = (direction + 3) % 4; // Counter-clockwise
}

// Turn the robot to the right
void turnRight() {
    API_turnRight();
    direction = (direction + 1) % 4; // Clockwise
}

// Turn the robot around
void turnAround() {
    turnRight();
    turnRight();
}

// Main logic
int main(int argc, char* argv[]) {
    log("Running...");
    API_setColor(0, 0, 'G');
    API_setText(0, 0, "Start");

    while (1) {
        if ( x == GoalX && y == GoalY){
            log("Goal reached!");
            API_setColor(x, y, 'G');
            API_setText(x, y, "Goal");
            break;
        }
        // Implementation of the left hand rule.
        // 1- Always turn Right if you can
        else if (!API_wallRight()) {
            turnRight();
            API_moveForward();
            updatePosition();
        }
        // 2- If you can't go Right, go straight
        else if (!API_wallFront()) {
            API_moveForward();
            updatePosition();
        }
        // 3- If you cannot turn Right, or go straight, turn left
        else if (!API_wallLeft()) {
            turnLeft();
        }
        // 4- Dead end: turn around
        else {
            turnAround();
        }

        API_setColor(x, y, 'Y');
    }
}
