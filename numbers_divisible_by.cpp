// :D
#include <iostream>
#include <cstring>
using namespace std;

int main(int argc, char* argv[]){

    // checks if there are sufficient arguments given
    if(argc != 4) {
        cout << "this requires 3 arguments";
        return 1;
    }

    // initialize the variables
    int num1 = stoi(argv[1]);
    int num2 = stoi(argv[2]);
    int divisor  = stoi(argv[3]);
    int i;

    // if the second number is larger than the first
    if (num2 > num1) {
        for (i = num1; i <= num2; i++) {
            // is the number divisible by the divisor?
            if (i % divisor == 0) {
                //prints the number
                cout << i << "\n";
            }

        }
    }

    //the first number is larger than the second
    else {
        for(i = num1; i >= num2; i--) {
            if (i % divisor == 0) {
                cout << i << "\n";
            }
        }
    }

    return 0;

}