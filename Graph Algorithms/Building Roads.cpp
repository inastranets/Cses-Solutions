#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> adj;
vector<bool> visited;

void dfs(int s) {
	if(visited[s])
		return;
	visited[s] = true;
	for(auto u:adj[s])
		dfs(u);
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, m;

	cin >> n >> m;

	visited.assign(n + 1, 0);
	adj.resize(n + 1);

	for(int i = 0; i < m; ++ i) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	vector< pair<int,int> > ans;

	for(int i = 1; i<= n; ++ i) {
		if(!visited[i]) {
			dfs(i);
			if(i > 1)
				ans.push_back({i - 1, i});
		}
	}

	cout << ans.size() << '\n';
	for(auto u:ans)
		cout << u.first << ' ' << u.second << '\n';

	return 0;
}
