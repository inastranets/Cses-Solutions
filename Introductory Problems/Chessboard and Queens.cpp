#include <bits/stdc++.h>

using namespace std;

/*
 * The problem can by solved using baktracking by placing queens to the board
 * row by row. More precisely, exactly one queen will be placed on each row
 * so that no queen attacks any of the queens placd before. A solution has
 * been found when all 8 queens have been placed on the board.
 * */

const int N = 8;
char board[N][N];
bool col[N], diag1[2 * N - 1], diag2[2 * N - 1];
int ans = 0;

void search(int y) {
	if(y == N) {
		++ ans;
		return;
	} 
	for(int x = 0; x < N; ++ x) {
		if(board[y][x] == '*' || col[x] || diag1[x + y] || diag2[x - y + N - 1])
			continue;
		col[x] = diag1[x + y] = diag2[x - y + N - 1] = true;
		search(y + 1);
		col[x] = diag1[x+y] = diag2[x - y + N - 1] = false;
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	for(int i = 0; i < N; ++ i)
		for(int j = 0; j < N; ++ j)
			cin >> board[i][j];

	search(0);

	cout << ans;
	return 0;
}
