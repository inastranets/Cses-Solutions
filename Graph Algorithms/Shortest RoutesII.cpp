#include <bits/stdc++.h>

using namespace std;

const long long INF = (unsigned long long)1e18;
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, m, tt;
	cin >> n >> m >> tt;
	vector<vector<long long> > edges(n, vector<long long>(n, INF));
	for(int i = 0; i < m; ++i) {
		int a, b, w;
		cin >> a >> b >> w;
		-- a, -- b;
		if(w < edges[a][b])
			edges[a][b] = edges[b][a] = w;
	}

	for(int k = 0; k < n; ++k)
		for(int i = 0; i < n; ++i)
			for(int j = 0; j < n; ++j)
				edges[i][j] = min(edges[i][j], edges[k][i] + edges[j][k]);

	while(tt--) {
		int u, v;
		
		cin >> u >> v;

		-- u, -- v;

		if(edges[u][v] == INF)
			edges[u][v] = edges[v][u] = -1;

		else if(u == v)
			edges[u][v] = edges[v][u] = 0;

		cout << edges[u][v] << '\n';
	}
	return 0;
}
