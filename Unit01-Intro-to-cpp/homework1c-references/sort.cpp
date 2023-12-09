#include <iostream>
#include <string>

using namespace std;

void sort(std::string& a, std::string& b, std::string& c) {
    std::string placeholder;

    if (a > b) {
        placeholder = a;
        a = b;
        b = placeholder;
    }
    if (a > c) {
        placeholder = a;
        a = c;
        c = placeholder;
    }
    if (b > c) {
        placeholder = b;
        b = c;
        c = placeholder;
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