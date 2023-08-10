#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	vector<int> tower;
	for(int i = 0; i < n; ++i) {
		int val;
		cin >> val;
		auto it = upper_bound(tower.begin(), tower.end(), val);
		if(it == tower.end())
			tower.push_back(val);
		else
			tower[it - tower.begin()] = val;
	}
	cout << tower.size();
	return 0;
}
