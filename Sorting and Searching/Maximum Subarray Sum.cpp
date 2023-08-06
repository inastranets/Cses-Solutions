#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	vector<long long> nums(n);
	for(auto &el:nums)
		cin >> el;

 	long long sum = 0, best = LONG_MIN;
 	for(auto el:nums) {
 		sum = max(el, sum + el);
 		best = max(best, sum);
 	}
 	cout << best;
	return 0;
}
