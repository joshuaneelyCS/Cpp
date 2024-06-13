//  :)
#include <iostream>
using namespace std;

#include <string>
using namespace std;

int main() {

    // initialize variables
    string oper;
    string response;
    int num1;
    int num2;
    bool end = false;

    while(true) {

        // gets the operation and checks to see if its empty
        while(true) {
            cout << "operation: ";
            getline(cin, oper);

            //checks for valid input, if false, it restarts the loop
            // in retrospect, I could have put the names in a list and compared the input to the list
            if (oper.empty()) {
                end = true;
                break;
                //cout << "what";
            } else if (oper != "add" && oper != "subtract" && oper != "multiply" && oper != "divide" && oper != "mod") {
                cout << oper << " isn't a valid operation\n";
            } else {
                break;
            }
        }

        // if it exited the loop and it was a no line space, it quits
        if(end == true) {
            break;
        }

        // gets the left operand and checks to see if its empty
        cout << "left operand: ";
        getline(cin, response);
        if(response.empty()) {
            break;
        }
        num1 = stoi(response);

        // gets the right operand and checks to see if its empty
        cout << "right operand: ";
        getline(cin, response);
        if(response.empty()) {
            break;
        }
        num2 = stoi(response);

        // checks the input and performs the corresponding operation
        if(oper == "add")
        {
            cout << num1 + num2 << "\n";
        } else if (oper == "subtract")
        {
            cout << num1 - num2 << "\n";
        } else if (oper == "multiply")
        {
            cout << num1 * num2 << "\n";
        } else if (oper == "divide")
        {
            cout << num1 / num2 << "\n";
        } else
        {
            cout << num1 % num2 << "\n";
        }
    }
}