vector<int> Solution::getRow(int A) {
    vector<int> row;
    int C = 1;
    A++;
	for (int i = 1; i <= A; i++)
	{
	    row.push_back(C);
	    C = C * (A - i) / i;
	}
	return row;
}
