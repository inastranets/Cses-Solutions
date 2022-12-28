#include <bits/stdc++.h>

using namespace std;

// time complexity: O(2^n)
// space: O(n)

void hanoi(int n, int target, int dest) {
	if(n == 1) {
		cout << target << ' ' << dest << '\n';
	} else {
		int helper = 6 - target - dest;
		hanoi(n - 1, target, helper);
		cout << target << ' ' << dest << '\n';
		hanoi(n - 1, helper, dest);
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int n; 
	cin >> n;

	cout << pow(2, n) - 1 << '\n';

	hanoi(n, 1, 3);

	return 0;
}
