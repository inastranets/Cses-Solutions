#include <bits/stdc++.h>

using namespace std;

vector<vector<int> > adj;
vector<bool> visited;
vector<int> cycle;

bool dfs(int v, int p) {
	visited[v] = true;
	for(auto u:adj[v]) {
		cycle.push_back(u);
		if(!visited[u]) {
			if(dfs(u, v))
				return true;
		} else if(u != p) {
			return true;
	 	}
	 	cycle.pop_back();
	}
	return false;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, m; 
	cin >> n >> m;
	adj.resize(n+1);
	visited.assign(n+1,0);
	for(int i = 0; i < m; ++i) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	for(int i = 1; i <= n; ++i) {
		cycle.push_back(i);
		if(!visited[i] && dfs(i, 0)) {
			vector<int> ans = { *cycle.rbegin() };
			for(auto v = cycle.rbegin() + 1; v != cycle.rend(); ++v) {
				
				ans.push_back(*v);
				
				if(*v == *cycle.rbegin())
					break;
			}

			cout << ans.size() << '\n';
			for(auto u:ans)
				cout << u << ' ';

			return 0;
		}
		cycle.pop_back();	
	}
	
	cout << "IMPOSSIBLE";

	return 0;
}
