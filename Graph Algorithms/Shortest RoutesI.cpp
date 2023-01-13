#include <bits/stdc++.h>
 
using namespace std;
 
const long long INF = LLONG_MAX;
 
priority_queue< pair<long long,long long>, vector<pair<long long, long long>>, greater<pair<long long,long long>> > q;
vector< vector< pair<long long, long long> > > adj;
vector<long long> distanse;
vector<bool> visited;
 
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
 
  int n, m;
  
  cin >> n >> m;
 
  adj.resize(n + 1);
  visited.assign(n + 1, 0);
  distanse.assign(n + 1, INF);

  for(int i = 0; i < m; ++i) {
    int a, b, w;
    cin >> a >> b >> w;
    adj[a].push_back({b,w});
  }     

  distanse[1] = 0;
  q.push({0, 1});
  while(!q.empty()) {
    int u = q.top().second;
    q.pop();
    if(visited[u]) continue;
    visited[u] = true;
    for(auto [v,w]:adj[u]) {
      if(distanse[v] > distanse[u] + w) {
        distanse[v] = distanse[u] + w;
        q.push({distanse[v], v});
      }
    }
  }
 
  for(int i = 1; i <= n; ++i)
    cout << distanse[i] << ' ';
  
  return 0;
}
