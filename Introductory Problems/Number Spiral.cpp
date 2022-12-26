#include <bits/stdc++.h>

using namespace std;

void solve() {
	int x, y;
	cin >> y >> x;
	int n = max(y, x); // size of matrix nxn
	long long main_diag = 1ll*n*n-(n-1); // number in main diag
	long long ans = main_diag;
	// as the coor increse or decrease, the ans decreses or increses
	// for the difference (x, y)
	if(n&1) {
		if(y < x)
			ans += x - y;
		else 
			ans -= y - x;
	} else {
		if(y < x)
			ans -= x - y;
		else 
			ans += y - x;
	}
	cout << ans << '\n';
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int tt;
	cin >> tt;
	while(tt --) {
		solve();
	}
	return 0;
}
