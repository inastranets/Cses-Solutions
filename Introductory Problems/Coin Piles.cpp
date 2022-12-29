#include <bits/stdc++.h>

using namespace std;

/*
 * Lets say x times we take 2 from a, and 1 from b
 * and y times we take 2 from b and 1 from a
 *
 * meaning:
 * a = 2x + 1y
 * b = 1x + 2y
 *
 * on solving from a and b
 * 2a - b = 3x
 * 2b - a = 3y
 *
 * x and y should be non negative, and from here we can drive (a+b)%3==0
 *     
 * */

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int tt;
	cin >> tt;
	while(tt --) {
		long long a, b;
	
		cin >> a >> b;
	
		/* It means ... When we reduce a by 2 then we must reduce b by 1
		 * and when we reduce a by 1 the we must reduce b by 2. 
		 * If We assume that we take x times 2 and y times 1 to reach
		 * a to 0 then we must take x times 1 and y times 2 to reduce
		 * b to 0. i.e
		 * a = 2x + 1y
		 * b = 1x + 2y
		 * 
		 * */
		if((a + b) % 3 == 0 && 2 * a >= b && 2 * b >= a)
			cout << "YES";
		else
			cout << "NO";
		cout << '\n';
	}

	return 0;
}
