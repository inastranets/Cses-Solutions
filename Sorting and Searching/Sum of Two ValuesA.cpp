#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n, x;
	cin >> n >> x;
	vector<pair<int,int> > nums(n);
	for(int i = 0; i < n; ++i) {
	 	cin >> nums[i].first, nums[i].second = i + 1;
	}

	sort(nums.begin(), nums.end());

	int l = 0, r = n - 1;
	while(l < r) {
		if(nums[l].first + nums[r].first == x) {
			 return cout << nums[l].second << ' ' << nums[r].second, 0;
		} else if(nums[l].first + nums[r].first < x) {
	  	++ l;
		} else {
			--r;
		}
	}
	cout << "IMPOSSIBLE";
	return 0;
}
