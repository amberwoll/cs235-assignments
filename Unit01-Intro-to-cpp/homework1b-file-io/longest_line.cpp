#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

using namespace std;

int main(int argc, char const* argv[]) {
    ifstream inputFile(argv[1]);

    string longestLine;
    string line;
    string word;
    int wordCount = 0;
    int longestLineCount = 0;

    while (getline(inputFile, line)) {
        stringstream ss(line);
        while (ss >> word) {
            wordCount++;
        }
        if (wordCount > longestLineCount) {
            longestLine = line;
            longestLineCount = wordCount;
        };
        wordCount = 0;
    };

    cout << longestLine << endl;

    return 0;
}
