/*
 * Since n is not large, we can simply iterate over all possible subsets
 * time complexity: O(2^n)
 * */

#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n; 
	
	cin >> n;
	
	int weights[n];
	long long totalWeight = 0;
	
	for(int i = 0; i < n; ++ i) {
		cin >> weights[i];
		totalWeight += weights[i];
	}

	long long ans = LONG_MAX;
	for(int i = 0; i < (1 << n); ++ i) {
		long long subsetSum = 0;
		for(int j = 0; j < n; ++ j)
			if(i&(1<<j))
				subsetSum += weights[j];
		ans = min(ans, abs(totalWeight - 2 * subsetSum));
	}
	cout << ans;
	return 0;
}
