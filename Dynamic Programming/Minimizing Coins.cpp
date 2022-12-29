#include <bits/stdc++.h>

using namespace std;

const int INF = 1e9;
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, x;
	
	cin >> n >> x;

	vector<int> coins(n);

	for(int &in:coins)
		cin >> in;

	int dp[x + 1];
	memset(dp, 0x0, sizeof(dp));
	
	for(int i = 1; i <= x; ++ i) {
		dp[i] = INF;
		for(int c:coins)
			if(i - c >= 0)
				dp[i] = min(dp[i], dp[i - c] + 1);
	}

	if(dp[x] >= INF)
		dp[x] = -1;
	cout << dp[x];

	return 0;
}
