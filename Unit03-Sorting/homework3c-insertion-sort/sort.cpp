#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

void insertSort(vector<string> &arrange) {
    int n = arrange.size();
    for (int i = 1; i < n; ++i) {
        string save = arrange[i];
        int j = i - 1;
        while (j >= 0 && arrange[j] > save) {
            arrange[j + 1] = arrange[j];
            j = j - 1;
        }
        arrange[j + 1] = save;
    }
}

int main(int argc, char const* argv[]) {
    vector<string> lines; 
    ifstream inputFile(argv[1]);

    string line;
    while (getline(inputFile, line)) {
        if (line.empty()) {
            continue;
        }
        lines.push_back(line);
    }
    inputFile.close();

    insertSort(lines);

    for (const auto &line : lines) {
        cout << line << endl;
    }

    return 0;
}