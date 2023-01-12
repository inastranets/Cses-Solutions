#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> adj;
vector<int> cl;

void dfs(int s) {
	for(auto u:adj[s]) {
		if(cl[u] == 0) {
			cl[u] = 3 - cl[s];
			dfs(u);					
		} else if(cl[u] == cl[s]) {
			cout << "IMPOSSIBLE";
			exit(0);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	cin >> n >> m;

	adj.resize(n+1);
	cl.assign(n+1, 0);
	
	for(int i = 0; i < m; ++i) {
		int a, b;
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}

	for(int i = 1; i <= n; ++i) {
		if(cl[i] == 0) {
			cl[i] = 1;
			dfs(i);
		}
	}
	for(int i = 1; i<=n; ++i)
		cout << cl[i] << ' ';
	return 0;
}
