#include <iostream>
#include "SLList.h"
using namespace std;

int main() {
    SLList<string> linkedList;

    linkedList.push_back("charity");
    linkedList.push_back("hope");
    linkedList.push_back("faith");
    linkedList.push_back("rich");
    linkedList.print();


    return 0;
};