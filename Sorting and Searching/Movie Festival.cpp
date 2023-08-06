#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;
	vector<pair<int,int>> time;
	for(int i = 0; i < n; ++i) {
		int start, end;
		cin >> start >> end;
		time.push_back({end,start});
	}

	sort(time.begin(), time.end());

	int prev = 0, ans = 0;
	for(auto t:time) {
		if(prev <= t.second) 
		{
			prev = t.first;
			++ ans;
		}
	}
	cout << ans;
	return 0;
}
