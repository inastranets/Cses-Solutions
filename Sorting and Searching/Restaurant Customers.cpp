#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;
	vector<pair<int,int>> time;
	for(int i = 0; i < n; ++i) {
		int arrive, leave;
		cin >> arrive >> leave;
		time.push_back({arrive, +1});
		time.push_back({leave, -1});
	}

	sort(time.begin(), time.end());

	int cnt = 0, best = 0;
	for(auto t:time) {
		cnt += t.second;
		best = max(best, cnt);	
	}
	
	cout << best;

	return 0;
}
