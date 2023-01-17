#include <bits/stdc++.h>

using namespace std;

const long long INF = 1ll<<62;
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	cin >> n >> m;
	vector<tuple<int,int,int>> edges;
	for(int i = 0; i < m; ++i) {
		int a, b, w;
		cin >> a >> b >> w;
		edges.push_back({a,b,w});
	}
	vector<long long> distanse(n + 1, INF);
	vector<int> p(n + 1, -1);
	distanse[1] = 0;
	int step;
	for(int i = 1; i<=n;++i) {
		step=0;
		for(auto e:edges) {
			int a, b, w;
			tie(a,b,w) = e;
			if(distanse[a] + w < distanse[b]) {
				distanse[b] = distanse[a] + w;
				p[b] = a;
				step = b;
			}
		}
	}
	if(step) {
		cout << "YES\n";
		vector<int> cycle;
		for(int i = 1; i<=n; ++i)
			step = p[step];
		for(int v = step; ;v=p[v]) {
			cycle.push_back(v);
			if(cycle.size() > 1 && v == step)
				break;
		}
		reverse(cycle.begin(), cycle.end());
		for(auto v:cycle)
			cout << v << ' ';
	} else {
		cout << "NO";
	}
	return 0;
}
