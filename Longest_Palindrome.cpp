//
// Created by Joshua Neely on 6/21/24.
//
#include <string>
#include <iostream>

std::string find_island(std::string text, int pos) {
    std::string island;
    int distance = 1;
    while (true) {
        if (pos - distance >= 0) {
            if (text[pos - distance] == text [pos + distance]) {
                island = text.substr((pos - distance), (1 + distance + distance));
                distance++;
            } else {
                break;
            }
        } else {
            break;
        }
    }
    return island;

}

std::string longest_palindrome(std::string text) {
    std::remove_if(text.begin(), text.end(), isspace);
    std::string curr_long = "";

    for (int i = 0; i < text.size(); i++) { //sets the character to the newest palendrome
        std::string finding = find_island(text, i);
        if (finding.size() > curr_long.size()) {
            curr_long = finding;
        }
    }
    return curr_long;
}

int main() {
    std::string myPali = longest_palindrome("asd ftkcpapcktf asdf");
    std::cout << myPali << std::endl;
}

