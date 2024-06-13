#include <iostream>
using std::cin, std::cout, std::endl;

#include <string>
using std::string;

#include <fstream>
using std::ifstream;

#include <set>
using std::set;

#include <vector>
using std::vector;

bool input(string& line) {
    return getline(cin, line) && !line.empty();
}

int main(int argc, char const* argv[]) {
    // Write your code here
    if (argc == 1) {
        string line;
        set <string> fruit;
        while(input(line)) {
            auto iterator = fruit.insert(line);
            if(iterator.second) {
                cout << line << endl;
            }
        }


    } else if(argc == 2) {
            ifstream rfile(argv[1]);
            string line;
            set <string> fruit;
            vector <string> println;
            while (getline(rfile, line) && line != "") {
                auto iterator = fruit.insert(line);
                    if(iterator.second) {
                        println.push_back(line);
                    }
            }
            for (auto item : println) {cout << item << endl;}
            rfile.close();
    }

    return 0;

}
