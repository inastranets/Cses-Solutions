#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, x;

	cin >> n >> x;

	int weight[n];
	for(int i = 0; i < n; ++ i)
		cin >> weight[i];
	// Let weight[p] denote the weight of person p. We define two functions: redes(S)
	// is the minimum number of rides for a subset S, and last(S) is minimum weight of the last rider.
	// The idea is to go through all people who belong to S and optimally choose the last person p who
	// enters the elevator. Each such choice yields a subproblem for a smaller suset of people. 
	// If last (S\p) + weight[p] <=x, we can add p to the last ride. Otherwise, we have ot reserve a new
	// ride that initially only contains p
	pair<int, int> best[1 << n];
	best[0] = {0,0};
	for(int s = 1; s < (1 << n); ++ s) {
		// init value: n + 1 rider are needed
		best[s] = {n + 1, 0};
		for(int p = 0; p < n; ++ p) {
			if(s & (1 << p)) {
				auto option = best[s^(1<<p)];
				if(option.second + weight[p] <= x) {
					// add p to an existing ride
					option.second += weight[p];
				} else {
					// reserve a new rider for p
					++ option.first;
					option.second = weight[p];
				}
				best[s] = min(best[s], option);
			}
		}
	}
	
	cout << best[(1<<n)-1].first + 1;

	return 0;
}
