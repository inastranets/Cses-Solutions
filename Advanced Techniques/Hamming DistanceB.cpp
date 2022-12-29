#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, k; 
	cin >> n >> k;
	vector<int> nums(n);
	for(int i = 0; i < n; ++ i) {
		string s;
		cin >> s;
		reverse(s.begin(), s.end());
		for(int j = 0; j < k; ++ j)
			nums[i] += (s[j] == '1') * (1 << j);
	}

	int ans = 32;
	for(int i = 0; i < n; ++ i) 
		for(int j = i + 1; j < n; ++ j)
			ans = min(ans, __builtin_popcount(nums[i] ^ nums[j]));
	
	cout << ans;

	return 0;
}
