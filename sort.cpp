#include <iostream>
using namespace std;
#include <string>
using namespace std;

void sort(std::string& a, std::string& b, std::string& c) {

    // implement sort here
    string list[3] = {a,b,c};
    string swap;
    if(a>b) {
        swap = b;
        b = a;
        a = swap;
    }

    if(b>c) {
        swap = c;
        c = b;
        b = swap;
    }

    if(a>b) {
        swap = b;
        b = a;
        a = swap;
    }

}

int main(int argc, char const* argv[]) {
    if (argc < 4) {
        std::cerr << "Usage: " << argv[0] << " a b c" << std::endl;
        return 1;
    }

    std::string a = argv[1];
    std::string b = argv[2];
    std::string c = argv[3];

    sort(a, b, c);

    std::cout << a << ' ' << b << ' ' << c << std::endl;

    return 0;
}
