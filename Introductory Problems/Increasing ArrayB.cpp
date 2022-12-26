#include <bits/stdc++.h>

using namespace std;

const int mxN = 2e5;
int nums[mxN + 1];
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	long long ans = 0;
	for(int i = 0; i < n; ++ i)
		cin >> nums[i];

	for(int i = 0; i < n - 1; ++ i)
	{
		if(nums[i] > nums[i+1])
		{
			int dif = nums[i] - nums[i + 1];
			nums[i+1] += dif;
			ans += dif;
		}
	}
	cout << ans;
	return 0;
}
