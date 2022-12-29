#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, k; 

	cin >> n >> k;
	
	vector<bitset<32> > bits(n);
	for(int i = 0; i < n; ++ i) {
		string s;
		cin >> s;
		bits[i] = static_cast<bitset<32> > (s);
	}
	
	int ans = 32;
	for(int i = 0; i < n; ++ i) 
		for(int j = i + 1; j < n; ++ j) 
			ans = min(ans, (int)(bits[i] ^ bits[j]).count());	
	
	cout << ans;

	return 0;
}
