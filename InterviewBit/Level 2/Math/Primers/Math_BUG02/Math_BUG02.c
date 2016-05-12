int ** squareSum(int A, int *len1, int *len2) {
	*len2 = 2;
	*len1 = 0;
	int a, b;

	for (a = 0; a * a < A; a++) {
		for (b = a; b * b < A; b++) {
			if (a * a + b * b == A) {
				*len1 = *len1 + 1;
			}
		}
	}

	int **ans = (int **)malloc(*len1 * sizeof(int *));
	int index = 0;

	for (a = 0; a * a < A; a++) {
		for (b = a; b * b < A; b++) {
			if (a * a + b * b == A) {
				ans[index] = (int *)malloc(2 * sizeof(int));
				ans[index][0] = a;
				ans[index][1] = b;
				index++;
			}
		}
	}

	return ans;
}
