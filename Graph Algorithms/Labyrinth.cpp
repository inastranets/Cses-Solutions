#include <bits/stdc++.h>

using namespace std;

typedef pair<int,int> ii;

const int mxN = 1e3;

char Labyrinth[mxN][mxN];
bool visited[mxN][mxN];
int prevStep[mxN][mxN];
string moves = "ULRD";
int dy[] = {-1, 0, 0, +1};
int dx[] = {0, -1, +1, 0};

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n, m;
	cin >> n >> m;
	ii A, B;
	for(int i = 0; i < n; ++i) {
		for(int j = 0; j < m; ++ j) {
			cin >> Labyrinth[i][j];
			if(Labyrinth[i][j] == 'A')
				A = {i, j};
			else if(Labyrinth[i][j] == 'B')		
				B = {i, j};
		}
	}
	queue<ii> q;
	q.push(A);
	visited[A.first][A.second] = true;
	while(!q.empty()) {
		ii s = q.front();
		q.pop();
		for(int i = 0; i < 4; ++ i) {

			ii v = {s.first + dy[i], s.second + dx[i]};

			if(v.first < 0 || v.first >= n || v.second < 0 || v.second >= m)
				continue;
			if(Labyrinth[v.first][v.second] == '#')
				continue;
			if(visited[v.first][v.second])
				continue;

			visited[v.first][v.second] = true;
			q.push(v);
			prevStep[v.first][v.second] = i;
		}
	}

	if(visited[B.first][B.second]) {
		cout << "YES\n";
		vector<int> steps;
		while(B!=A) {
			int step = prevStep[B.first][B.second];
			steps.push_back(step);
			B = {B.first-dy[step], B.second-dx[step]};
		}
		reverse(steps.begin(), steps.end());
		cout << steps.size() << '\n';
		for(auto s:steps)
			cout << moves[s];
	} else {
		cout << "NO\n";
	}
        return 0;
}
