#include <iostream>
using std::cout, std::endl;
#include <string>
using std::stoi, std::string;
#include <queue>
using std::priority_queue;

#include "input.h"

int main(int argc, char const* argv[]) {
    // Write your code here
    priority_queue<string> pq;
    string response;
    while (input("What do you want to do? ", response)) {
        string name;
        string priority;
        if (response == "add") {
            input("Name: ", name);
            input("Priority: ", priority);

            int numcheck = stoi(priority);
            if (numcheck < 10) {
                priority = "0" + priority;
            }

            string data = priority + " - " + name;
            pq.push(data);

        } else if (response == "take") {
            if (!pq.empty()) {
                cout << pq.top() << endl;
                pq.pop();
            } else {
                cout << "There are no more people in line" << endl;
            }
        } else if (response == "") {
            break;
        }
    }
    return 0;
}
