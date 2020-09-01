#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, s1 = 0, s2 = 0, i, j;
    cin >> n;
    vector<vector<int>> a(n);
    for (i = 0; i < n; i++) {
        a[i] = vector<int>(n);
        for (j = 0; j < n; j++) {
            cin >> a[i][j];
            if (j == i)
                s1 += a[i][j];
            if (j + i + 1 == n)
                s2 += a[i][j];
        }
    }
    cout << abs(s1 - s2);
    return 0;
}