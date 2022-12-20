#include <bits/stdc++.h>

using namespace std;

const int mxN = 2e5;
bool used[mxN + 1];
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n;
  cin >> n;
  for(int i = 0; i < n - 1; ++ i)
  {
	  int x;
	  cin >> x;
	  used[x] = true;
  }

  for(int i = 1; i <= n; ++ i)
  {
	  if(!used[i]) {
		  cout << i;
		  break;
	  }
  }
  /*
   * I don't think there's anything to say here,
   * it's just brute-force
   * */
  return 0;
}
