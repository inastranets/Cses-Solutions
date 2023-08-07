#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n, x;
	cin >> n >> x;
	vector<int> nums(n);
	for(int &el:nums)
		cin >> el;

	int r = 0, ans = 0;
	long long sum = 0; 
	for(int l = 0; l < n; ++l) {
		while(r < n && sum < x) {
			sum += nums[r];
			++ r;
		}		
		if(sum == x)
			++ ans;
		sum -= nums[l];
	}
	
	cout << ans;

	return 0;
}
