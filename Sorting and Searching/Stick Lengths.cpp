#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	vector<int> length(n);
	for(int &len:length)
		cin >> len;

	sort(length.begin(), length.end());

	int meddium = length[n / 2];
	long long ans = 0;
	for(int &len:length)
		ans += abs(meddium - len);		
	cout << ans;
	return 0;
}
