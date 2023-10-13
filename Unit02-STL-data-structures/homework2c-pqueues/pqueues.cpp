#include <iostream>
#include <string>
#include <queue>
#include "input.h"

using namespace std;

int main(int argc, char const* argv[]) {
    priority_queue<string> PQ;
    string operation;
    cout << "What do you want to do? ";
    cin >> operation;
    if (operation == "add") {
        string name;
        cout << "Name: ";
        cin >> name;
        int priority;
        cout << "Priority: ";
        cin >> priority;
        string stringPriority = (priority < 10) ? "0" + to_string(priority) : to_string(priority);
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
    return 0;
}
