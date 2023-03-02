#include <bits/stdc++.h>

#define ALL(x) x.begin(), x.end()

using namespace std;

typedef long long ll;
typedef pair<int,int> ii;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif

	int n, q;
	cin >> n >> q;
	vector<int> nums(n);
	for(int i = 0; i < n; ++i) 
		cin >> nums[i];


	long long prefix[n];
	memset(prefix, 0x0, sizeof prefix);
	prefix[0] = nums[0];
	for(int i = 1; i < n; ++i)
		prefix[i] = prefix[i-1] + nums[i];
	while(q--) {
		int a, b;
		cin >> a >> b;
		-- a, -- b;
		cout << prefix[b] - prefix[a] + nums[a] << '\n';
	}
	return 0;
}
