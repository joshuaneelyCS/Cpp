#include <iostream>
using std::cout, std::endl, std::cin;
#include <string>
using std::string;
#include <fstream>
using std::ifstream;
#include <vector>
using std::vector;

void insertion_sort(vector<string>& listWords) {
    for (int i = 1; i < listWords.size(); i++) {

        // Grab item i and save it
        string item = listWords[i];

        // Shift the sort stuff to the right until I find where item belongs
        int j = i;
        while (j > 0 && item < listWords[j-1]) {
            listWords[j] = listWords[j-1];
            j--;
        }

        // Insert the item in it's sorted position
        listWords[j] = item;

    }
}

void print(vector<string> listWords) {
    for(int i = 0; i < listWords.size(); i++) {
        cout << listWords[i] << endl;
    }
}

int main(int argc, char const* argv[]) {
    // Write your code here
    if (argc == 1) {
        vector<string> words;
        string response;
        while (getline(cin,response) && response != "") {
            words.push_back(response);
        }

        //sorting implementation
        insertion_sort(words);
        print(words);

    } if (argc == 2) {
        ifstream inFile(argv[1]);
        vector<string> words;
        string response;
        while (getline(inFile,response) && response != "") {
            words.push_back(response);
        }

        insertion_sort(words);
        print(words);
    }

    return 0;
}
