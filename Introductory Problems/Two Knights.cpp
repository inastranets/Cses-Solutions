#include <bits/stdc++.h>

using namespace std;

int main() {
	int n;
	cin >> n;

	/*
	 *First we need to figure out how many ways there are to place two
	 * knights on the board. Since the first knight can be placed anywhere
	 * on k*k possitions ans the second knight anywhere else k*k-1 possitions
	 * (k*k*(k*k-1)) / 2 we divide by two since the knights are indistinguishable
	 * and we want to remove duplicate cases.
	 *
	 * Now, all we have to find out is how many of these possitions pout both
	 * knights under attack. As we can see in the following image there are eight
	 * different attacking configurations that can be made by a knight.
	 *                    *    *
	 *                  *        *
	 *                       x 
	 *                  *        *
	 *                   *      *
	 * Since he board is a square we can deduce there are the same number of 
	 * attaacking positions for each of the eight configurations
	 * How many ways are there to place each of the configurations in a k * k board
	 * and given that one attack occupies a block of dimensins 2 * 3 (and vice-virsa)
	 * than we have (k - 1) * (k - 2) ways of placing the 2 * 3 blocks on the board.
	 * To giet the tota number of distinct attacking psitions we multiply this
	 * value by eight and divide it by 2 to remove the duplicates.
	 *
	 * -> f(k) = k * k (k * k - 1) / 2 - 8 * (k - 1) * (k - 2) / 2 <=>
	 *  k * k * (k * k - 1) / 2 - 4 * (k - 1) * (k - 2) 
	 *
	 *
	 * */
	for(int k = 1; k <= n; ++ k)
		cout << 1ll * k * k * (k * k - 1) / 2 - 4 * (k - 1) * (k - 2) << '\n';
	return 0;
}
