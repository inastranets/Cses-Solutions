#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n;
  cin >> n;
  int s = n;
  for(int i = 0; i < n - 1; ++ i)
  {
	  int x;
	  cin >> x;
	  s -= x;
	  s += i + 1;
  }
  cout << s;
 
  return 0;
}
/*
I think everything is clear here, 
after we subtract all the numbers, 
we will get 0 as a result, 
therefore, if we add numbers from 1 to n to the result, 
we will get the missing number
*/
