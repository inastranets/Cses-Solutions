#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, x;
	cin >> n >> x;
	vector<int> nums(n+1);
	unordered_map<long long, vector<pair<int,int>> > mp;

	for(int i = 1; i <= n; ++i) {
		cin >> nums[i];
		for(int j = 1; j < i; ++j) {
			int psum = nums[i] + nums[j];
			if(psum >= x) continue;
			if(mp.find(x - psum) != mp.end()) {
				for(auto p:mp[x-psum])
					if(p.first != i && p.second != i && p.first != j && p.second != j)
						return cout << p.first << ' ' << p.second << ' ' << i << ' ' << j, 0;
			} else {
				mp[psum].push_back({i,j});
			}			
		}
	}

	cout << "IMPOSSIBLE";
	
	return 0;
}
