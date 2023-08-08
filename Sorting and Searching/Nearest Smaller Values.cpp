#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	stack<pair<int,int>> nums;
	for(int i = 1; i <= n; ++i) {
		int x;
		cin >> x;
		while(!nums.empty() && nums.top().first >= x) {
				nums.pop();
		}

		if(!nums.empty()) {
			cout << nums.top().second << ' ';	
		} else {
			cout << 0 << ' ';
		}
		nums.push({x,i});
	}
	return 0;
}
