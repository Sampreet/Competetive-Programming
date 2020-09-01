#include <iostream>

using namespace std;

int main() {
    int n = 5;
    long long min = 1000000001, max = 0, sum = 0, a;

    while (n--) {
        cin >> a;

        if (a < min) {
            min = a;
        }
        if (a > max) {
            max = a;
        }
        sum += a;
    }

    cout << sum - max << ' ' << sum - min << endl;

    return 0;
}