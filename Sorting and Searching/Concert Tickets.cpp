#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m;
	cin >> n >> m;
	multiset<int> ticket;
	for(int i = 0; i < n; ++i) {
		int price;
		cin >> price;
		ticket.insert(price);
	}

	for(int i = 0; i < m; ++i) {
		int price;
		cin >> price;
		auto it = ticket.upper_bound(price);
		if(it == ticket.begin()) {
			cout << -1;
		} else {
			--it;
			cout << *it;
			ticket.erase(it);
		}
		cout << '\n';
	}
	return 0;
}
