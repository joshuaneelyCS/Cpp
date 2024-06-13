#include <cstdlib>  // atof
#include <iostream>

using std::abs;
using namespace std;

const double EPSILON = 0.0001;

int main (int argc, char* argv[]) {

    // verifies that the user input 1 argument
    if(argc != 2) {
        cout << "prod requires 1 argument";
        return 1;
    }

    double num = stod(argv[1]);

    if (num < 0) {
        cout << "Input must be greater than 0\n";
        return  1;
    }

    double lower = 0;
    double upper = num;
    double mid = (upper + lower) / 2;

    while(abs(mid*mid - num) > EPSILON) {
        mid = (upper + lower) / 2;
        if (mid * mid > num) {
            upper = mid;
        } else {
            lower = mid;
        }
        cout << mid << " " << "(" << mid*mid << ")" << "\n";

    }



}


// :)
