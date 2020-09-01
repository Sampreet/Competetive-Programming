#include <stdio.h>

int main() {
    int hh, mm, ss, i;
    char period;

    scanf("%d:%d:%d%c%*c", &hh, &mm, &ss, &period);

    if (hh == 12 && period == 'A') {
        hh = 0;
    }
    if (hh != 12 && period == 'P') {
        hh += 12;
    }

    printf("%02d:%02d:%02d", hh, mm, ss);
    return 0;
}

