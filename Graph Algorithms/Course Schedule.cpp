#include <bits/stdc++.h>

#define ALL(x) x.begin(), x.end()

using namespace std;

vector<vector<int>> adj;
vector<int> cl;
vector<int> topological_order;
bool check = true;
void dfs(int s) {
	cl[s] = 1;
	for(auto u:adj[s]) {
		if(cl[u] == 0) {
			dfs(u);
		} else if(cl[u] == 1) {
			check = false;
		} 
	}
	topological_order.push_back(s);
	cl[s] = 2;
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	cin >> n >> m;
	adj.resize(n + 1);
	cl.assign(n + 1, 0);
	for(int i = 0; i < m; ++i) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
	}

	for(int i = 1; i <= n; ++i) {
 		if(cl[i] == 0) {
 			dfs(i);
 		}
	}
	if(check) {
		reverse(ALL(topological_order));
		for(auto v:topological_order)
			cout << v << ' ';
	
	} else {
		cout << "IMPOSSIBLE";
	}
	return 0;
}
