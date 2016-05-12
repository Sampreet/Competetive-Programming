int trailingZeroes(int A) {
    int count=0, i=0;
    for (i=5; A/i>=1; i*=5)
          count+=A/i;

    return count;
}
