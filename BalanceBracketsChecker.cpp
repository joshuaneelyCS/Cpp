//
// Created by Joshua Neely on 6/24/24.
//
#include <iostream>
using std::cout, std::endl;

#include <string>
#include <stack>

char match_pair(char &symbol) {
    if (symbol == '(') {
        return ')';
    } else if (symbol == '{'){
        return '}';
    } else if (symbol == '[') {
        return ']';
    } else if (symbol == ')') {
        return '(';
    } else if (symbol == '}'){
        return '{';
    } else if (symbol == ']') {
        return '[';
    } else {
        throw std::invalid_argument("symbol is not parenthesis, bracket, or curly brace");
    }
}

bool is_open_bracket(char &symbol) {
    if (symbol == '(' || symbol == '{' || symbol == '[') {
        return true;
    }
    return false;
}

bool is_closed_bracket(char &symbol) {
    if (symbol == ')' || symbol == '}' ||  symbol == ']') {
        return true;
    }
    return false;
}

bool match_parenthesis(const std::string& text_set) {

    std::stack<char> brackets;

    for (char i : text_set) {
        char curr_symbol = i;
        if (is_open_bracket(curr_symbol)) {
            brackets.push(curr_symbol);
        } else if (is_closed_bracket(curr_symbol)) {
            if (brackets.empty()) {
                return false;
            } else if (match_pair(i) != brackets.top()) {
                return false;
            }
            brackets.pop();
        }
    }
    return true;
}

#include <string>
int main() {
    bool test = match_parenthesis("()(([{}()]))");
    cout << test << endl;
}