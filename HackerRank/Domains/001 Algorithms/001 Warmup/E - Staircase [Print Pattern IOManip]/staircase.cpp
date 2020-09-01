#include <iomanip>
#include <iostream>
#include <string>

using namespace std;

int main() {
    int n, i;
    cin >> n;
    for (i = 0; i < n; i++) {
        cout << setw(n) << right << string(i + 1, '#') << endl;
    }
    return 0;
}