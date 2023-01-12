#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	cin >> n >> m;
	vector<vector<int>> adj(n+1);
	for(int i = 0; i < m; ++i) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	queue<int> q;
	bool visited[n+1];
	memset(visited, 0x0, sizeof visited);
	vector<int> prev(n+1);
	q.push(1);
	while(!q.empty()) {
		int s = q.front();
		q.pop();
		for(auto u:adj[s]) {
			if(visited[u]) continue;
			visited[u] = true;
			prev[u] = s;
			q.push(u);			
		}
	}
	if(visited[n]) {
		vector<int> steps;
		while(n > 1) {
   			steps.push_back(n);
   			n = prev[n];	
		}
		steps.push_back(1);
		reverse(steps.begin(), steps.end());
		cout << steps.size() << '\n';
		for(auto u:steps)
			cout << u << ' ';
	} else {
		cout << "IMPOSSIBLE";		
	}
	return 0;
}
