#include <iostream>
#include <string>
#include <queue>
#include "input.h"

using namespace std;

int main(int argc, char const* argv[]) {
    priority_queue<string> PQ;
    string operation;
    cout << "What do you want to do? ";
    getline(cin, operation);
    while (true) {
        if (operation == "add") {
            string name;
            cout << "Name: ";
            getline(cin, name);
            string priority;
            cout << "Priority: ";
            getline(cin, priority);
            string stringPriority = (stoi(priority) < 10) ? "0" + priority : priority;
            string entry = stringPriority + " - " + name;
            PQ.push(entry);
        }
        else if (operation == "take") {
            if (!PQ.empty()) {
                string next = PQ.top();
                PQ.pop();
                cout << next << endl;
            } else {
                cout << "There are no more people in line" << endl;
            }
        }
        else if (operation == "") {
            return 0;
        }
        else {
            cout << operation << " isn't a valid operation" << endl;
        }
        cout << "What do you want to do? ";
        getline(cin, operation);
    }
    return 0;
}
