#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	string s;
	cin >> s;
	int c[26];
	memset(c, 0x0, sizeof(int)*26);
	for(auto u:s)
		++ c[u - 'A'];

	int count = 0, mid = -1;
	for(int i = 0; i < 26; ++ i) {
		if(c[i] > 0 && c[i] & 1) {
			++ count;
			if(count == 2)
			{
				return cout << "NO SOLUTION", 0;
			}
			mid = i;
		}
	}

	string ans;
	for(int i = 0; i < 26; ++ i) {
		if(c[i] > 0 && c[i] % 2 == 0) {
			for(int j = 0; j < c[i] / 2; ++ j)
				ans.push_back('A' + i);
			c[i] = 0;
		}
	}
	cout << ans;
	if(mid != -1) { 
		for(int i = 0; i < c[mid]; ++ i)
			cout << char('A' + mid);
	} 

	for(int i = ans.size() - 1; i>=0; --i)
		cout << ans[i];
	return 0;
}
