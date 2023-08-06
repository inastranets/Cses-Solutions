#include <bits/stdc++.h>

using namespace std;

int main() {
	int n;
	cin >> n;
	vector<int> idx(n);
	for(int i = 0; i < n; ++i) {
		int x;
		cin >> x;
		idx[x-1] = i;	
	}

	int ans = 0;
	for(int i = 1; i < n; ++i)
		if(idx[i-1] > idx[i])
			++ ans;		

	cout << ans+1;

	return 0;
}
