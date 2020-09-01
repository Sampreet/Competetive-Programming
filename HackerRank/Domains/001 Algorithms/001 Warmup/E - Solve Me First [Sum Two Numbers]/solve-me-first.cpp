#include <iostream>

using namespace std;

void solveMeFirst(int a, int b) {
    cout << a + b;
}

int main() {
    int num1, num2;
    int sum;
    cin >> num1 >> num2;
    solveMeFirst(num1, num2);
    return 0;
}