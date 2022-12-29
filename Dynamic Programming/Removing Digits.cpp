#include <bits/stdc++.h>

using namespace std;

const int INF = 1e9 + 7;
int main() {
	int n;

	cin >> n;
	
	int dp[n + 1];
	dp[0] = 0;
	for(int i = 1; i <= n; ++ i) {
		dp[i] = INF;
		int digit = i;
		while(digit > 0) {
			if(digit % 10 != 0) 
				dp[i] = min(dp[i], dp[i - (digit % 10)] + 1);
			digit /= 10;
		}
	}

	cout << dp[n];

	return 0;
}
