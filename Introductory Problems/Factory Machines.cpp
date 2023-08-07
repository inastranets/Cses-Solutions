#include <bits/stdc++.h>

using namespace std;

int n, k;
vector<int> p;
bool valid(long long x) {
	long long s = 0;
	for(int t:p)
		s += x/t;

	return s >= k;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n >> k;
	p.resize(n);
	for(int &t:p)	
		cin >> t;

	sort(p.begin(), p.end());

	long long x = -1;
	for(long long b = 1ll * k * p[0]; b >= 1; b/=2)
		while(!valid(x + b)) x += b;

	cout << x + 1;
	return 0;
}
