#include <iostream>

using namespace std;

int main() {
    int n, count = 0;
    long long max = 0, a;

    cin >> n;

    while (n--) {
        cin >> a;

        if (a == max) {
            count ++;
        }
        else if (a > max) {
            max = a;
            count = 1;
        }
    }

    cout << count << endl;

    return 0;
}