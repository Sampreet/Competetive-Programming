#include <iomanip>
#include <iostream>

using namespace std;

int main() {
    int N, i, a, p = 0, n = 0, z = 0;
    cin >> N;
    for (i = 0; i < N; i++) {
        cin >> a;
        
        p += a > 0 ? 1 : 0; 
        n += a < 0 ? 1 : 0;
        z += a == 0 ? 1 : 0;
    }
    
    cout << fixed << setprecision(6) << (float)p / ((float)N) << endl << (float)n / ((float)N) << endl << (float)z / ((float)N);
    return 0;
}