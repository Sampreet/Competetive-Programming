#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, i, a = 0, b = 0;
    vector<int> arr_a(3), arr_b(3);

    for (i = 0; i < 3; i++) {
        cin >> n;
        arr_a[i] = n;
    }

    for (i = 0; i < 3; i++) {
        cin >> n;
        arr_b[i] = n;
    }

    for (i = 0; i < 3; i++) {
        a += arr_a[i] > arr_b[i] ? 1 : 0;
        b += arr_a[i] < arr_b[i] ? 1 : 0;
    }

    cout << a << ' ' << b << endl;

    return 0;
}