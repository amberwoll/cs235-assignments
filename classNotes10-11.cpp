#include <iostream> 
using namespace std;

// normal version
int sum(int n) {
    int s = 0;
    for (int i = 1; i <= n; i++) {
        s += i
    };

    return s;
}

// recursive version
int sumRec(int n) {
    //base case: principle 1: have a good base case
    if (n <= 0) {
        return 0:
    }
    //recursive step: principle 2: have a recursive step that is correct
    return n + sumRec(n-1);
}

int main(int argc, char *argv[]) {
    int n = atoi(argv[1]);

    cout << "sum " << n << " = " << sum(n) << endl;
    cout << "sumRec " << n << " = " << sumRec(n) << endl;

    return 0
}
