#include <bits/stdc++.h>

using namespace std;

int tree[1000006];

int read(int idx){
    int sum = 0;
    while (idx > 0){
        sum += tree[idx];
        idx -= (idx & -idx);
    }
    return sum;
}

void update(int idx ,int val){
    while (idx <= 1000004){
        tree[idx] += val;
        idx += (idx & -idx);
    }
}

int main() {
	int t;
	cin >> t;
	while(t--) {
	    int n;
	    cin >> n;
	    vector<int>arr(n);
	    for(int i = 0; i < n; i++)
            scanf("%d", &arr[i]);
	    memset(tree, 0, sizeof(tree));
	    printf("0 ");
	    update(arr[0], 1);
	    for(int i = 1; i < n; i++) {
	        printf("%d ", read(arr[i] - 1));
	        update(arr[i], 1);
	    }
	    printf("\n");
	}
	return 0;
}
