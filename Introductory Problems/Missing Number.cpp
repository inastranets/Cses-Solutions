#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n;
  cin >> n;
  long long total = 0;
  for(int i = 0; i < n - 1; ++ i) {
	  int x;
	  cin >> x;
	  total += x;
  }
  // 1 + 2 + ... + n = n * ( n + 1) / 2
  cout << 1ll * n * (n + 1) / 2 - total;
  return 0;
}
