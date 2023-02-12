#include <bits/stdc++.h>

using namespace std;

int n;
vector<int> weight;
long long rec(int i, long long sum1, long long sum2) {
	if(i == n) 	
		return abs(sum1-sum2);
	return min(rec(i+1, sum1+weight[i],sum2), rec(i+1,sum1, sum2+weight[i]));
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> n;
	weight.resize(n);
	for(auto &w:weight)
		cin >> w;

	cout << rec(0,0,0);
  
	return 0;
}
