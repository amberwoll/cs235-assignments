#include <iostream>
#include <string>

#include "Grid.h"

int main(int argc, char* argv[]) {
    // Write your code here

if (maze[r][c] == 0)
        return false;
    
    if ((r == 3) && (c == 3) && (maze[r][c] == 1))
        return true;
    
    if ((r < 0) || (c < 0) || (r >= 4) || (r >= 4))
        return false;

    //if we have been there before base case

    if (solveMaze(maze, r-1, c) ||
        solveMaze(maze, r+1, c) ||
        solveMaze[r][c+1] || 
        solveMaze[r][c-1])

    return false;
}