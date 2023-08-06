#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n, x;
	cin >> n >> x;
	map<int,int> nums;
	for(int i = 1; i <= n; ++i) {
		int el;
		cin >> el;
		if(nums.find(x - el) != nums.end()) {
			return cout << i << ' ' << nums[x - el], 0;
		}	
		nums[el] = i;
	}
	cout << "IMPOSSIBLE";
	return 0;
}
