#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	vector<int> book(n);
	
	long long total = 0;
	int mx = INT_MIN;
	for(int &t:book) {
		cin >> t;
		total += t;
		mx = max(mx, t);
	}

	cout << max(total, 1ll * 2 * mx);
	
	return 0;
}
