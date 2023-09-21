#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int main(int argc, char const* argv[]) {
    ifstream inputFile(argv[1]);
    ofstream outputFile(argv[2]);

    string first;
    string last;
    int points;
    double factor;

    while (inputFile >> first >> last >> points >> factor) {
        double newPoints = factor * points;
        outputFile << last << ", " << first << ": " << newPoints << endl;
    }

    return 0;
}
