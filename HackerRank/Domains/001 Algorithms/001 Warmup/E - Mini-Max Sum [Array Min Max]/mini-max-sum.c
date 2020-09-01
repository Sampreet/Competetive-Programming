#include <stdio.h>

int main() {
    int n = 5;
    long long min = 1000000001, max = 0, sum = 0, a;

    while (n--) {
        scanf("%lld", &a);

        if (a < min) {
            min = a;
        }
        if (a > max) {
            max = a;
        }
        sum += a;
    }

    printf("%lld %lld", sum - max, sum - min);

    return 0;
}