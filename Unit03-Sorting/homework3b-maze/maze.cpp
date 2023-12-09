// #include <iostream>
// #include <fstream> 
// #include <string>

// #include "Grid.h"

// bool solveMaze(Grid& maze, Grid& visited, int r, int c, int l) {
//     if (r < 0 || c < 0 || l < 0 || r >= maze.height() || c >= maze.width() || l >= maze.depth() || maze.at(r, c, l) == 0 || visited.at(r, c, l) == true)
//         return false;

//     if ((r == maze.height() - 1 && c == maze.width() - 1 && l == maze.depth() - 1) && (maze.at(r, c, l) == 1))
//         return true;

//     visited.at(r, c, l) = true;

//     if (solveMaze(maze, visited, r - 1, c, l) || solveMaze(maze, visited, r + 1, c, l) ||
//         solveMaze(maze, visited, r, c - 1, l) || solveMaze(maze, visited, r, c + 1, l) ||
//         solveMaze(maze, visited, r, c, l - 1) || solveMaze(maze, visited, r, c, l + 1)) {
//         return true;
//     }
//     visited.at(r, c, l) = false;
//     return false;
// }

// int main(int argc, char* argv[]) {
//     std::ifstream inFile(argv[1]);
//     std::ofstream outFile(argv[2]);
//     Grid maze;
//     inFile >> maze;

//     Grid visited;
//     visited = maze;
//     for (int r = 0; r < visited.height(); ++r) {
//         for (int c = 0; c < visited.width(); ++c) {
//             for (int l = 0; l < visited.depth(); ++l) {
//                 visited.at(r, c, l) = false;
//             }
//         }
//     }

//     if (solveMaze(maze, visited, 0, 0, 0)) {
//         outFile << "SOLUTION\n";
//         int currentLevel = 0;
//         int currentRow = 0;
//         int currentColumn = 0;

//         while (!(currentRow == maze.height() - 1 && currentColumn == maze.width() - 1 && currentLevel == maze.depth() - 1)) {
//             outFile << currentRow << " " << currentColumn << " " << currentLevel << '\n';

//             if (currentRow - 1 >= 0 && maze.at(currentRow - 1, currentColumn, currentLevel) == 1 && visited.at(currentRow - 1, currentColumn, currentLevel)) {
//                 currentRow--;
//             } else if (currentRow + 1 < maze.height() && maze.at(currentRow + 1, currentColumn, currentLevel) == 1 && visited.at(currentRow + 1, currentColumn, currentLevel)) {
//                 currentRow++;
//             } else if (currentColumn - 1 >= 0 && maze.at(currentRow, currentColumn - 1, currentLevel) == 1 && visited.at(currentRow, currentColumn - 1, currentLevel)) {
//                 currentColumn--;
//             } else if (currentColumn + 1 < maze.width() && maze.at(currentRow, currentColumn + 1, currentLevel) == 1 && visited.at(currentRow, currentColumn + 1, currentLevel)) {
//                 currentColumn++;
//             } else if (currentLevel - 1 >= 0 && maze.at(currentRow, currentColumn, currentLevel - 1) == 1 && visited.at(currentRow, currentColumn, currentLevel - 1)) {
//                 currentLevel--;
//             } else if (currentLevel + 1 < maze.depth() && maze.at(currentRow, currentColumn, currentLevel + 1) == 1 && visited.at(currentRow, currentColumn, currentLevel + 1)) {
//                 currentLevel++;
//             }
//         }
//         outFile << maze.height() - 1 << " " << maze.width() - 1 << " " << maze.depth() - 1 << '\n';
//     } else {
//         outFile << "NO SOLUTION\n";
//     }

//     inFile.close();
//     outFile.close();
//     return 0;
// }

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

#include "Grid.h"

bool solveMaze(Grid& maze, std::vector<std::string>& path, int r, int c, int l) {
    if (r < 0 || c < 0 || l < 0 || r >= maze.height() || c >= maze.width() || l >= maze.depth() || maze.at(r, c, l) == 0) {
        return false;
    }

    if (r == maze.height() - 1 && c == maze.width() - 1 && l == maze.depth() - 1 && maze.at(r, c, l) == 1) {
        path.push_back(std::to_string(r) + " " + std::to_string(c) + " " + std::to_string(l));
        return true;
    }

    maze.at(r, c, l) = 0; // Mark as visited

    if (solveMaze(maze, path, r - 1, c, l) || solveMaze(maze, path, r + 1, c, l) ||
        solveMaze(maze, path, r, c - 1, l) || solveMaze(maze, path, r, c + 1, l) ||
        solveMaze(maze, path, r, c, l - 1) || solveMaze(maze, path, r, c, l + 1)) {
        path.push_back(std::to_string(r) + " " + std::to_string(c) + " " + std::to_string(l));
        return true;
    }

    return false;
}

int main(int argc, char* argv[]) {
    std::ifstream inFile(argv[1]);
    std::ofstream outFile(argv[2]);
    Grid maze;
    inFile >> maze;

    std::vector<std::string> path;

    if (solveMaze(maze, path, 0, 0, 0)) {
        outFile << "SOLUTION\n";
        for (int i = path.size() - 1; i >= 0; --i) {
            outFile << path[i] << '\n';
        }
    } else {
        outFile << "NO SOLUTION\n";
    }

    inFile.close();
    outFile.close();
    return 0;
}