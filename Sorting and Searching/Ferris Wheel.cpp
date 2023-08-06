#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, x;
	cin >> n >> x;
	vector<int> weight(n);
	for(auto &w:weight)
		cin >> w;

	sort(weight.begin(), weight.end());

	int l = 0, r = n - 1;
	int ans = 0;
	while(l <= r) {
		if(weight[l] + weight[r] <= x) {
			++ ans;
			++l;
			--r;
		} else {
			++ ans;
			-- r;
		}
	}
	
	cout << ans;

	return 0;
}
