#include <iostream>

using namespace std;


bool solveMaze(int maze[4][4], int r, int c) {

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

int main() {
    int maze[4][4] = {{1,1,0,0},
                  {0,1,0,0},
                  {1,1,1,0},
                  {0,0,1,1}};
    return 0;
}