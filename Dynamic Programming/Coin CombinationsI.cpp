#include <bits/stdc++.h>

using namespace std;

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

	dp[0] = 1;
	for(int i = 1; i <= x; ++ i) 
		for(int c:coins)
			if(i - c >= 0)
				dp[i] = (dp[i] + dp[i - c]) % (unsigned int)(1e9+7);
	
	cout << dp[x];

	return 0;
}
