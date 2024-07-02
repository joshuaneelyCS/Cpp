//
// Created by Joshua Neely on 7/1/24.
//

#include <unordered_map>
using std::unordered_map;
#include <string>
using std::string;

int lengthOfLongestSubstring(string s) {
    unordered_map<char, int> myMap;

    int longest = 0;
    int curr_long = 0;
    int head = 0;
    int tail = 0;

    while (tail < s.size()) {
        if (myMap.count(s[tail])) {

            curr_long = tail - head;

            if (curr_long > longest) {
                longest = curr_long;
            }

            char char1 = s[head];
            char char2 = s[tail];

            while (char1 != char2) {
                myMap.erase(char1);
                head++;
                char1 = s[head];
            }
            head++;
            tail++;

        }
        else {
            myMap[s[tail]]++;
            tail++;
        }
    }
    curr_long = tail - head;
    if (curr_long > longest) {
        longest = curr_long;
    }
    return longest;
}

int main() {
    int num = lengthOfLongestSubstring("abcabcbb");
    return num;
}