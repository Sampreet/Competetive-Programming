#include <stdio.h>

int main() {
    int n, **a, s1 = 0, s2 = 0, i, j;
    scanf("%d", &n);
    a = (int **)malloc(n * sizeof(int *));
    for (i = 0; i < n; i++) {
        a[i] = (int *)malloc(n * sizeof(int));
        for (j = 0; j < n; j++) {
            scanf("%d", &a[i][j]);
            if (j == i)
                s1 += a[i][j];
            if (j + i + 1 == n)
                s2 += a[i][j];
        }
    }
    free(a);
    printf("%d", abs(s1 - s2));
    return 0;
}