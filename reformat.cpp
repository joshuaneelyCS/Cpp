//  :-)
#include <iostream>
using namespace std;

#include <fstream>
using namespace std;

#include <sstream>
using std::istringstream;

#include <string>
using std::string;

int main(int argc, char* argv[]) {

    //reads in the file
    ifstream infile(argv[1]);
    ofstream outfile(argv[2]);
    string line;
    while (getline(infile, line)) {
        istringstream linestream(line);
        string firstname;
        string lastname;
        int points;
        double factor;

        linestream >> firstname >> lastname >> points >> factor;

        outfile << lastname << ", " << firstname << ": " << points * factor << "\n";

    }



}