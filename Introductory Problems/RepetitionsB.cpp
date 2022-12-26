#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	string s;
	int best = 0, count = 0;
	cin >> s;
	
	char x = '.';
	for(char ch:s) {
		if(x == ch) {
			++ count;
		} else {
			x = ch;
			count = 1;
		}
		best = max(best, count);
	}
	cout << best;
	return 0;
}
