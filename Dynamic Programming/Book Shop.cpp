#include <bits/stdc++.h>

using namespace std;

const int mxN = (unsigned int)1e3;
const int mxW = (unsigned int)1e5;
int price[mxN], pages[mxN];
int dp[mxN + 1][mxW + 1];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, x;
	
	cin >> n >> x;

	for(int i = 0; i < n; ++ i)
		cin >> price[i];

	for(int i = 0; i < n; ++ i)
		cin >> pages[i];

	for(int k = 1; k <= n; ++ k) {
		for(int s = 0; s <= x; ++ s) {
			dp[k][s] = dp[k - 1][s];
			if(s >= price[k-1] && dp[k][s] < dp[k-1][s-price[k-1]] + pages[k-1]) {
				dp[k][s] = dp[k-1][s-price[k-1]] + pages[k-1];
			}
		}
	}

	cout << dp[n][x];

	return 0;
}
