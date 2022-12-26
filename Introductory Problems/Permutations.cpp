#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int n; 
	cin >> n;
	if(n == 1)
		cout << 1;
	else if(n < 4) // if n < 4 cannot build beatiful permutataion
		cout << "NO SOLUTION";

	// if n % 2 != 0 will output all odd ones staring from n to  1 
	// after all even ones from n - 1 to 2 then we will get a 
	// beautiful permutation.The same thing whe n is even, just the oposite

	else if(n & 1) { 
		for(int i = n; i >= 1; i -= 2)
			cout << i << ' ';
		for(int i = n - 1; i >= 2; i -= 2)
			cout << i << ' ';
	} else {
		for(int i = n - 1; i >= 1; i -= 2)
			cout << i << ' ';
		for(int i = n; i >= 2; i -= 2)
			cout << i << ' ';
	}
	return 0;
}
