#include <stdio.h>

int main() {
    int n, count = 0;
    long long max = 0, a;

    scanf("%d", &n);

    while (n--) {
        scanf("%lld", &a);

        if (a == max) {
            count ++;
        }
        else if (a > max) {
            max = a;
            count = 1;
        }
    }

    printf("%d", count);

    return 0;
}