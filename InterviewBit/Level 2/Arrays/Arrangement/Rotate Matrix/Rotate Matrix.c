void rotate(int** A, int n11, int n12) {
    int layer,i;
    for (layer = 0; layer < n11 / 2; layer++) {
		int last = n11 - 1 - layer;
		for (i = layer; i < last; i++) {
			int offset = i - layer;
			int top = A[layer][i];
			A[layer][i] = A[last - offset][layer];
			A[last - offset][layer] = A[last][last - offset];
			A[last][last - offset] = A[i][last];
			A[i][last] = top;
		}
	}
}
