#include <iostream>
using namespace std;
#include <string>
using namespace std;
#include <fstream>
using namespace std;
#include <sstream>
using std::istringstream;

void standard(int num, string file) {
    ifstream rfile(file);
    if(rfile.is_open()) {
        string line;
        string one;
        string myline;
        for (int i = 0; i < num; i++) {
            if (getline(rfile, line)) {
                cout << line << "\n";
            }
        }
    } else {
        cerr << "File does not exist" << endl;
    }
}

int main(int argc, char const* argv[]) {
    // Write your code here
    if(argc == 1) {
        for(int i = 0; i < 10; i++) {
            //cout << "// ";
            string response;
            getline(cin, response);
            cout << response << endl;
        }
    } else if(argc == 2) {
        string value = argv[1];
        if(value[0] == '-') {
            value.erase(0,1);
            int num = stoi(value);
            for(int i = 0; i < num; i++) {
                //cout << "// ";
                string response;
                getline(cin, response);
                cout << response << endl;
            }
        } else {
            standard(10, value);
        }
    }
    else if(argc == 3) {
            string value = argv[1];
            value.erase(0,1);
            int num = stoi(value);
            string file = argv[2];
            standard(num, file);
        }
    return 0;
}
