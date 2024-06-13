#include <iostream>
using std::cout, std::endl;

#include <string>
using std::string;

#include <vector>
using std::vector;

#include <fstream>
using std::ifstream, std::ofstream;

#include "Grid.h"

bool find_maze_path(Grid& grid, int row, int col, int level, vector<string>& solution) {
    string srow = std::to_string(row);
    string scol = std::to_string(col);
    string slevel = std::to_string(level);
    solution.push_back(srow + " " + scol + " " + slevel + "\n");
    if(col > (grid.width() - 1) || col < 0) {
        solution.pop_back();
        return false;
    } else if(row > (grid.height() -1) || row < 0) {
        solution.pop_back();
        return false;
    } else if(level > (grid.depth() -1) || level < 0) {
        solution.pop_back();
        return false;
    } else if(grid.at(row, col, level) == 0 || grid.at(row, col, level) == 2) {
        solution.pop_back();
        return false;
    }
    if(col == (grid.width()-1) && row == (grid.height()-1) && level == (grid.depth()-1)) {
        return true;
    }
    grid.at(row, col, level) = 2;
    if(find_maze_path(grid, row, col-1, level, solution) || find_maze_path(grid, row, col+1, level, solution) || find_maze_path(grid, row-1, col, level, solution) || find_maze_path(grid, row+1, col, level, solution) || find_maze_path(grid, row, col, level-1, solution) || find_maze_path(grid, row, col, level+1, solution)) {
        return true;
    } else {
        solution.pop_back();
        return false;
    }
}

int main(int argc, char* argv[]) {
    // Write your code here
    ifstream inFile(argv[1]);
    ofstream outFile(argv[2]);
    Grid maze;
    inFile >> maze;

    vector <string> mySolution;

    if (find_maze_path(maze, 0, 0, 0, mySolution) == true) {
        outFile << "SOLUTION" << endl;
        for(auto line : mySolution) {
            outFile << line;
        }
    } else {
        outFile << "NO SOLUTION";
    }

    inFile.close();
    outFile.close();

    return 0;
}
