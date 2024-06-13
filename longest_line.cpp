
#include <iostream>
using namespace std;

#include <fstream>
using namespace std;

#include <sstream>
using std::istringstream;

#include <string>
using std::string;

// function that counts the word in a stream
int count_words(string line) {
    stringstream ss(line);
    int count = 0;
    string token;
    while (ss >> token) { count++; }
    return count;
}

int main(int argc, char* argv[]) {

    // initializes variables
    ifstream file1(argv[1]);
    string line;
    string longest_line;
    int number_words = 0;
    int num_long_word;

    // goes through each line and counts the words. If the number of words exceeds previous record, the number and line is replaced with current line
    while(getline(file1, line)) {
        number_words = count_words(line);
        if(number_words > num_long_word) {
            num_long_word = number_words;
            longest_line = line;
        }
    }

    cout << longest_line << "\n";

    file1.close();
    return 0;
}
