//
// Created by Joshua Neely on 6/19/24.
//
#include <iostream>

#include <vector>
using std::vector;

//Given two vectors of ints with the same values in different order, and there is one value missing
//from the second vector, find_missing_value finds the missing value in the second vector
int find_missing_value(vector<int> first, vector<int> second) {
    bool found = false;

    for (int i = 0; i < first.size(); i++) {
        found = false;
        for (int j = 0; j < second.size(); j++) {
            if (first[i] == second[j]) { found=true; break;}
        }
        if (!found) {
            return first[i];
        }
    }

    //if program fails
    return 0;
}

int main() {
    vector<int> myVector = {1,2,3,4,5,6,7};
    vector<int> myVector2 = {7,1,4,5,6,3};
    int missing_value = find_missing_value(myVector, myVector2);
    std::cout << missing_value << std::endl;
}

