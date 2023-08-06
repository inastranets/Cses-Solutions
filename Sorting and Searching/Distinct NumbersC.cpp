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

	nums.resize(unique(nums.begin(), nums.end()) - nums.begin());

	cout << nums.size();
	return 0;
}
