#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int tt;
	cin >> tt;
	while(tt--) {
		long long x;
		cin >> x;
		-- x;
		long long l = 1, n = 1;
		// find which power of 10 our digit lies in
		// for example: for 1-9 we have 9 digits
		// 		for 10-99 we have 180 digits
		// 		for 100-999 we have 2700 digits ...etc
		while(x > l * 9 * n) {
			x -= l * 9 * n;
			++ l;
			n *= 10;
		}
		// set num to the actual number we lie on by adding x/len
		n += x / l;
		// make x the i-th digit of num
		x %= l;
		cout << to_string(n)[x] << '\n';
	}
	return 0;
}
