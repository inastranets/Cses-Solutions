#include <bits/stdc++.h>

using namespace std;

/*
 * Basic Algorithm
 * The first version of the algoithm does not contain any optimizations.
 * We simply use bracktracking to generate all possible path from the
 * upper-left corner to the lower-right corner and count the number of 
 * such paths.
 * *Number of recursive calls: 76 billion
 * */

/*
 * Optimization 1
 * If the path reaches the lower-right square before it has visited all
 * other squares of the grid, it is clear that it will not be possible
 * to complete the solution. Using the observation, we can terminate
 * the search immediately if we reach the lower-right square too early.
 *
 * * Number of recursive calls: 20 billion
 * */

/*
 * Optimization 2
 * If the path touches a wall and can turn either left or right, the grid
 * splits into two parts that contain unvisited squares. In this case, we 
 * cannot visit all squares anymore, so we can terminate the search.
 *
 * * Number of recursive calls: 221 million
 * */

/*
 * Optimization 3
 * The idea of Optimization 2 can be generalized: if the path cannot continue 
 * forward but can turn either left or right, the grid splits into two parts that
 * both contain unvisited squares. It is clear that we cannot visit all 
 * squares anymore, so we can terminate the search.
 *
 * *Number of recursive calls: 69 million
 *
 * Now is a good moment to stop optimizing the algorithm and see what we have 
 * achieved. The running time of the original algorithm was ~484s, and now after 
 * the optimizations, the running time is only ~0.6 seconds. Thus, the algorithm
 * became nearly 1000 times faster after the optimizations. 
 * */

const int DIR_LEN = 4;

int dr[DIR_LEN] = {-1, 0, 1, 0};

int dc[DIR_LEN] = {0, 1, 0, -1};

const int PATH_LEN = 48;  // length of all possible paths

int p[PATH_LEN];

const int GRID_SIZE = 9;  

// added border to all four sides so a 7x7 becomes a 9x9

bool onPath[GRID_SIZE][GRID_SIZE];


int tryPath(int pathIdx, int curR, int curC) {

	// Optimization 3

	if ((onPath[curR][curC - 1] && onPath[curR][curC + 1])

		&& (!onPath[curR - 1][curC] && !onPath[curR + 1][curC])) return 0;

	if ((onPath[curR - 1][curC] && onPath[curR + 1][curC])

		&& (!onPath[curR][curC - 1] && !onPath[curR][curC + 1])) return 0;


	if (curR == 7 && curC == 1) {  // reached endpoint before visiting all

		if (pathIdx == PATH_LEN) return 1;

		return 0;

	}


	if (pathIdx == PATH_LEN) return 0;


	int ret = 0;

	onPath[curR][curC] = true;


	// turn already determined:

	if (p[pathIdx] < 4) {

		int nxtR = curR + dr[p[pathIdx]];

		int nxtC = curC + dc[p[pathIdx]];

		if (!onPath[nxtR][nxtC]) ret += tryPath(pathIdx + 1, nxtR, nxtC);

	} 

	// see Java solution for optimization 4 implementation

	else {  // iterate through all four possible turns

		for (int i = 0; i < DIR_LEN; i++) {

			int nxtR = curR + dr[i];

			int nxtC = curC + dc[i];

			if (onPath[nxtR][nxtC]) continue;

			ret += tryPath(pathIdx + 1, nxtR, nxtC);

		}

	}

	// reset and return

	onPath[curR][curC] = false;

	return ret;

}


int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	string line;

	getline(cin, line);


	// convert path to ints

	for (int i = 0; i < PATH_LEN; i++) {

		char cur = line[i];


		if (cur == 'U') p[i] = 0;

		else if (cur == 'R') p[i] = 1;

		else if (cur == 'D') p[i] = 2;

		else if (cur == 'L') p[i] = 3;

		else p[i] = 4; //cur == '?'

	}


	// set borders of grid

	for (int i = 0; i < GRID_SIZE; i++) {

		onPath[0][i] = true;

		onPath[8][i] = true;

		onPath[i][0] = true;

		onPath[i][8] = true;

	}

	// initialize the inside of the grid to be completely empty

	for (int i = 1; i <= 7; i++) {

		for (int j = 1; j <= 7; j++) {

			onPath[i][j] = false;

		}

	}


	int startIdx = 0;

	int startR = 1;

	int startC = 1;  // always start path at (1, 1)

	int ans = tryPath(startIdx, startR, startC);

	cout << ans;

	return 0;
}

