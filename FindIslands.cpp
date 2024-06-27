//
// Created by Joshua Neely on 6/26/24.
//

//Given a 2D array of 1's and 0's, count the islands of 1's in the array

#include <iostream>
#include <vector>
using std::vector;
#include <string>
using std::string;

void island_helper(std::vector<std::vector<int>> &map, int y, int x) {
    map[y][x] =  -1;

    if (x + 1 < map[y].size() && map[y][x + 1] == 1) {
        island_helper(map, y, x + 1);
    }
    if (x - 1 > 0 && map[y][x - 1] == 1) {
        island_helper(map, y, x - 1);
    }
    if (y + 1 < map.size() && map[y + 1][x] == 1) {
        island_helper(map, y + 1, x);
    }
    if (y - 1 > 0 && map[y - 1][x] == 1) {
        island_helper(map, y - 1, x);
    }

}

int find_islands(std::vector<std::vector<int>> map) {

    int island_count = 0;

    for (int i = 0; i < map.size(); i++) {

        for (int j = 0; j < map[i].size(); j++) {


            int curr = map[i][j];
            // if it is a 0, skip over and change to visited
            if (curr == 1) {
                island_helper(map, i, j);
                island_count++;
            }

        }
    }
    return island_count;
}

int main() {

    std::vector<std::vector<int>> map = {{1,0,0,1,0},
                                         {0,1,0,1,1},
                                         {0,0,0,0,0},
                                         {1,1,0,0,0},
                                         {1,1,0,0,1}};

    int number_islands = find_islands(map); // expected to return 5

    std::cout << number_islands << std::endl;

}

// Implementation for a Island struct where islands can be saved and unique for future reference
struct Island {
private:
    int _size;
    vector<int> _location;
    char _id;

    Island(int size, vector<int> location, char id) : _size(size), _location(location), _id(id) { }

public:

    int size() const {
        return _size;
    }

    vector<int> location() const {
        return _location;
    }

    char id() const {
        return _id;
    }



};