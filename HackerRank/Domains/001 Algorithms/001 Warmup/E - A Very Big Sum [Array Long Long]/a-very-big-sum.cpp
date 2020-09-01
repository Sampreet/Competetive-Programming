#include <iostream>

using namespace std;

int main() {
    int n;
    long long a, sum = 0;
    cin >> n;
    while (n--) {
        cin >> a;
        sum += a;
    }
    cout << sum;
    return 0;
}