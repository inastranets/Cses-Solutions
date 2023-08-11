#include <bits/stdc++.h>

using namespace std;

int main() {	
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, x;
	cin >> n >> x;
	vector<pair<int,int>> nums;
	for(int i = 1; i <= n; ++i) {
		int x;
		cin >> x;
		nums.push_back({x, i});
	}

	sort(nums.begin(), nums.end());

	for(int i = 0; i < n; ++i) {
		int target = x - nums[i].first;
		
		int l = 0, r = n - 1;
		while(r - l > 1) {
			if(l != i && r != i && nums[l].first + nums[r].first == target) {
				return cout << nums[i].second << ' ' << nums[l].second << ' ' << nums[r].second, 0;
			} else if(nums[l].first + nums[r].first < target) {
				++ l;
			}	else {
				--r;
			}
		}
	}

	cout << "IMPOSSIBLE";

	return 0;
}
