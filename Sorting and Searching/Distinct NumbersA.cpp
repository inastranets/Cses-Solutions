#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	vector<int> nums(n);
	for(int &el:nums)
		cin >> el;


	sort(nums.begin(), nums.end());

	int ans = 0;
	for(int i = 1; i < n; ++i)
		if(nums[i] != nums[i-1])
			++ ans;
	
	cout << ans + 1;

	return 0;
}
