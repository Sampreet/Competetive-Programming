#include <stdio.h>

int main() {
    int N, i, a, p = 0, n = 0, z = 0;
    scanf("%d", &N);
    for (i = 0; i < N; i++) {
        scanf("%d", &a);
        
        p += a > 0 ? 1 : 0; 
        n += a < 0 ? 1 : 0;
        z += a == 0 ? 1 : 0;
    }
    printf("%0.06f\n%0.06f\n%0.06f\n", (float)p / ((float)N), (float)n / ((float)N), (float)z / ((float)N));
    return 0;
}