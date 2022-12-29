#include <bits/stdc++.h>

using namespace std;

/*
 * s1 - first string 
 * s2 - second string
 * rec(s1,  s2):               //n - s1.size(), m - s2.size()
 * 	if(n == 0 || m == 0): // it's mean s1 or s2 empty -> form transform we need n, or m operation if n = 0, we need m operation, if m = 0 we need n
 * 		return n + m
 *
 * 	  //If last character of two strings are same, nothing 
 *        // much to do. Ignore last characters and get count for
 *        // remaning strings.
 * 	  
 * 	  if(s1[n-1] == s2[m-1])
 * 	  	return distance(s1, s2, n - 1, m - 1)
 * 	  
 *        // if last characters are not same, consider all three
 *        // operations on last character of first string,
 *        // recursively sompute minimum cost for all three
 *        // operations and take minimum of three values.
 *
 * 	  else
 * 	  	return 1 + min(
 * 	  		       distance(s1, s2, n, m - 1), - insert a character at the end of x
 * 	  		       distance(s1, s2, n - 1, m), - remove the last character from x 
 * 	  		       distance(s1, s2, n - 1, m - 1) - match or midify the last character from x (replace)
 * 	  		       )
 * */

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	string s1, s2;

	cin >> s1 >> s2;

	int n = s1.size();
	int m = s2.size();

	int dp[n + 1][m + 1];
	for(int i = 0; i <= n; ++ i) {
		for(int j = 0; j <= m; ++ j) {
			if(i == 0 || j == 0)
				dp[i][j] = i + j;
			else if(s1[i - 1] == s2[j - 1])
				dp[i][j] = dp[i-1][j-1];
			else 
				dp[i][j] = 1 + min(dp[i-1][j], min(dp[i-1][j-1],dp[i][j-1]));
		}
	}

	cout << dp[n][m];
	
	return 0;
}
