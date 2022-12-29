#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  
  int n;
  
  cin >> n;
  
  int dp[n + 1];
  
  memset(dp, 0x0, sizeof(dp));
  
  dp[0] = 1;
  
  for(int i = 1; i <= n; ++ i) {
    for(int j = 1; j <= min(i, 6); ++ j)
      dp[i] = (dp[i] + dp[i - j]) % (unsigned int) (1e9 + 7);
  }
  
  cout << dp[n];
  
  return 0;
}
