#include <stdio.h>

char *repeatChar(char c, int k) {
    char *str = (char *)malloc((k + 1) * sizeof(char));
    str[k] = '\0';
    while (k--) {
        str[k] = c;
    }
    return str;
}

int main() {
    int n, i;
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        printf("%*s\n", n, repeatChar('#', i + 1));
    }
    return 0;
}