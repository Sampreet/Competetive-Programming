vector<vector<int> > Solution::generate(int A) {
    vector<vector<int>> rows;
    rows.resize(A);
    for(int line=1;line<=A;line++){
        int C = 1;
    	for (int i = 1; i <= line; i++)
    	{
    	    rows[line-1].push_back(C);
    	    C = C * (line - i) / i;
    	}
    }
	return rows;
}
