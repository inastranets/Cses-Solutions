// time complexity: O(n*m)
// space: O(n * m)
/*
classical "connected component counting" problem that can be solved with some kind of graph search algorithm, 
such as depth-first search, breadth-first search or even floodfill. 
*/
#include <bits/stdc++.h>

using namespace std;

int n, m;
char s[1000][1000];

bool isValid(int i, int j) {
	return i >= 0 && i < n && j >= 0 && j < m && s[i][j] == '.';
}

void dfs(int i, int j) {
	s[i][j] = '#';
	if(isValid(i + 1, j))
		dfs(i + 1, j);
	 if(isValid(i - 1, j))
		dfs(i - 1, j);
	if(isValid(i, j - 1))
		dfs(i, j - 1);
	if(isValid(i, j + 1))
		dfs(i, j + 1);
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	for(int i = 0; i < n; ++ i)
		for(int j = 0; j < m; ++ j)
			cin >> s[i][j];
	
	int ans = 0;
	for(int i = 0; i < n; ++ i)
		for(int j = 0; j < m; ++ j)
			if(isValid(i,j))
				dfs(i, j), ++ ans;
  
	cout << ans;
	
	return 0;
}
