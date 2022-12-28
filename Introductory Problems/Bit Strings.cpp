#include <bits/stdc++.h>

using namespace std;

/*
 * if f(n) is the function that gives us the number of
 * combinations then we can say the following:
 * f(n) = 2 * f(n - 1) this means that the number of
 * possible bit strings doubles every time we add a new
 * bit to the sequence. This make sense if think about
 * it, bacause by adding one bit, we will have all 
 * prevous combinations with the Nth bit assigned to 1 
 * plus all the previous combinations with the Nth bit
 * assigned to 0, hence doubling it.
 * */

int main() {
	int n; 
	cin >> n;
	long long ans = 1;
	for(int i = 1; i <= n; ++ i)
		ans = 2 * ans % (unsigned int)(1e9 + 7);
	cout << ans;
	return 0;
}
