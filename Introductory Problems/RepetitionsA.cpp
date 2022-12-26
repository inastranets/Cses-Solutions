#include <bits/stdc++.h>

using namespace std;

int main () {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	string s; 
	int best = 0;
	cin >> s;
	int i = 0;
	while(i < s.size()) {
		int j = i;
		int count = 0;
		while(s[j] == s[j++ + 1])
			++ count;
		best = max(best, count);
		i = j;
	}
	cout << best + 1;
	return 0;	
}
// time complexity: O(n)
