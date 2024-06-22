//
// Created by Joshua Neely on 6/21/24.
//
#include <string>
#include <iostream>

std::string find_odd_island(std::string text, int pos) {
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

std::string find_even_island(std::string text, int pos) {
    std::string island;
    int spaces_back = 0;
    int spaces_forward = 1;
    while (true) {
        if (pos - spaces_back >= 0 && pos + spaces_forward < text.size()) {
            if (text[pos - spaces_back] == text[pos + spaces_forward]) {
                island = text.substr((pos - spaces_back), (1 + spaces_forward + spaces_back));
                spaces_forward += 1;
                spaces_back += 1;
            } else {
                break;
            }
        } else {
            break;
        }
    }
    return island;
}

std::string find_longest_string(std::string text1, std::string text2) {
    if (text1.size() > text2.size()) {
        return text1;
    }
    return text2;
}

std::string longest_palindrome(std::string text) {
    std::remove_if(text.begin(), text.end(), isspace);
    std::string curr_long = "";
    std::string finding;
    for (int i = 0; i < text.size(); i++) { //sets the character to the newest palendrome
        if (text[i] == text[i + 1]) {
            finding = find_even_island(text, i);
            if (find_longest_string(finding, curr_long) == finding) {
                curr_long = finding;
            }
        }
        else {
            finding = find_odd_island(text, i);
            if (find_longest_string(finding, curr_long) == finding) {
                curr_long = finding;
            }
        }
    }
    return curr_long;
}

int main() {
    std::string myPali = longest_palindrome("While on a hike, I stopped to take a picture of the sunset, and there it was, a redder landscape than I had ever seen");
    std::cout << myPali << std::endl;
}

