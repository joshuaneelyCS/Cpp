// :)
#include <iostream>
using namespace std;

int main(int argc, char* argv[]) {

    // verifies that the user input 1 argument
    if(argc != 2) {
        cout << "prod requires 1 argument";
        return 1;
    }

    //initialize variables
    int num = stoi(argv[1]);

    //repeats the function until it reaches 1
    while (num != 1) {

        //prints the number
        cout << num << "\n";

        // if even
        if (num % 2 == 0) {
            num = num / 2;

        //if odd
        } else {
            num = (num*3) + 1;
        }

    }

    cout << "1\n";


}