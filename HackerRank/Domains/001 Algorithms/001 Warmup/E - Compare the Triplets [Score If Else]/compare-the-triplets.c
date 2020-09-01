#include <stdio.h>

int main() {
    int n, i, a = 0, b = 0;
    int *arr_a, *arr_b;

    arr_a = (int *)malloc(3 * sizeof(int));
    arr_b = (int *)malloc(3 * sizeof(int));

    for (i = 0; i < 3; i++) {
        scanf("%d", &n);
        arr_a[i] = n;
    }

    for (i = 0; i < 3; i++) {
        scanf("%d", &n);
        arr_b[i] = n;
    }

    for (i = 0; i < 3; i++) {
        a += arr_a[i] > arr_b[i] ? 1 : 0;
        b += arr_a[i] < arr_b[i] ? 1 : 0;
    }

    printf("%d %d", a, b);

    return 0;
}