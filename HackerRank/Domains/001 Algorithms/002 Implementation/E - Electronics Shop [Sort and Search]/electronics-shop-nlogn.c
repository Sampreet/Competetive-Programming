#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

void merge(long *arr, int l, int m, int r) {
    int i, j, k;
    int nl = m + 1 - l;
    int nr = r - m;

    long *L = (long *)malloc(nl * sizeof(long));
    long *R = (long *)malloc(nr * sizeof(long));

    for (i = 0; i < nl; i++) {
        L[i] = arr[l + i];
    }
    for (j = 0; j < nr; j++) {
        R[j] = arr[m + 1 + j];
    }

    i = 0;
    j = 0;
    k = l;

    while (i < nl && j < nr) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < nl) {
        arr[k] = L[i];
        i++;
        k++;
    }
    while (j < nr) {
        arr[k] = R[j];
        j++;
        k++;
    }

    free(L);
    free(R);
}

void mergeSort(long *arr, int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;

        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
        
        merge(arr, l, m, r);
    }
}

bool isBudgetLow(int b, int m, int n, long *arr_m, long *arr_n) {
    int i;
    long min_m = 1000001, min_n = 1000001;
    for (i = 0; i < m; i++) {
        if (arr_m[i] < min_m) {
            min_m = arr_m[i];
        }
    }
    for (i = 0; i < n; i++) {
        if (arr_n[i] < min_n) {
            min_n = arr_n[i];
        }
    }
    return b < min_m + min_n;
}

void electronicsShop(long b, int m, int n, long *arr_m, long *arr_n) {
    if (isBudgetLow(b, m, n, arr_m, arr_n)) {
        printf("-1");
    }
    else {
        int i, start, mid, stop;

        mergeSort(arr_m, 0, m - 1);
        mergeSort(arr_n, 0, n - 1);

        long maxi = arr_m[0] + arr_n[0];
        for (i = m - 1; i >= 0; i--) {
            start = 0;
            stop = n - 1;
            if (arr_m[i] + arr_n[stop] < maxi) {
                break;
            }
            while (stop >= 0 && stop <= n - 1 && arr_m[i] + arr_n[stop] > b) {
                mid = start + (stop - start) / 2;
                if (arr_m[i] + arr_n[mid] > b) {
                    stop = mid - 1;
                }
                else if (arr_m[i] + arr_n[mid] < b) {
                    start = mid + 1;
                }
                else {
                    stop = mid;
                }
            }
            if (stop >= 0 && stop <= n - 1 && arr_m[i] + arr_n[stop] > maxi) {
                maxi = arr_m[i] + arr_n[stop];
            }
        }
        printf("%ld", maxi);
    }
}

int main() {
    int m, n, i;
    long b, *arr_m, *arr_n;

    scanf("%ld %d %d", &b, &m, &n);

    arr_m = (long *)malloc(m * sizeof(long));
    arr_n = (long *)malloc(n * sizeof(long));
    for (i = 0; i < m; i++) {
        scanf("%ld", &arr_m[i]);
    }
    for (i = 0; i < n; i++) {
        scanf("%ld", &arr_n[i]);
    }
    
    electronicsShop(b, m, n, arr_m, arr_n);

    free(arr_m);
    free(arr_n);
}