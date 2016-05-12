int* spiralOrder(const int** a, int m, int n, int *length_of_array) {
	*length_of_array = m * n; // length of result array
	int *result = (int *) malloc(*length_of_array * sizeof(int));
	int i, k = 0, l = 0, p=0;
    while (k < m && l < n){
        for (i = l; i < n; ++i){
            result[p++]=a[k][i];
        }
        k++;
        for (i = k; i < m; ++i){
            result[p++]=a[i][n-1];
        }
        n--;
        if ( k < m){
            for (i = n-1; i >= l; --i){
                result[p++]=a[m-1][i];
            }
            m--;
        }
        if (l < n){
            for (i = m-1; i >= k; --i){
                result[p++]=a[i][l];
            }
            l++;
        }
    }
	return result;
}
