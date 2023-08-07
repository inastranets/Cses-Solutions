#include <bits/stdc++.h>

using namespace std;

int main() {
	int n;
	cin >> n;
	vector<int> nums(n);
	for(int &el:nums)
		cin >> el;

	set<int> uniq;
	int j = -1, best = 0;
	for(int i = 0; i < n; ++i) {
		while(j < n - 1 && !uniq.count(nums[j+1])) {
			++ j;
			uniq.insert(nums[j]);
		}
		best = max(best, j - i + 1);
		uniq.erase(nums[i]);
	}
	cout << best;
	return 0;
}
