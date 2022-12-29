#include <bits/stdc++.h>

using namespace std;

/*
 * Naive Solution
 * Loop through all subsets in the array and if sum is equal to x, then increase
 * our answer. Worst case this does about 2^40 operations, which way too slow.
 *
 * Meet in the Middle Solution
 *
 * We can divide the given array into two separate array. Let's say that the left
 * array runs from indexes 0 to n / 2 - 1, and right array runs from indexes n/2-1 to n - 1
 * Both arrays will be have at most 20 elements, so we can loop through all subset of these two
 * arrays in at most 2^21 operations, which is perfectly fine.
 *
 * Now that we've got the subset sums of these two separate arrays, we need to recombine 
 * them to search fro our answer. For every sum in the left, we can simly check how many elemens
 * of x - sum there are in right. This can be done using simple binary search.
 *
 * */

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, x;
	
	cin >> n >> x;
	
	vector<int> nums(n);

	for(int &in:nums)
		cin >> in;
	
	auto get_subset_sums = [&](int l, int r) -> vector<long long> {
		int len = r - l + 1;
		vector<long long> res;

		for(int i = 0; i < (1 << len); ++ i) {
			long long sum = 0;
			for(int j = 0; j < len; ++ j) {
				if(i & (1 << j))
					sum += nums[l + j];
			}
			res.push_back(sum);
		}
		return res;
	};

	vector<long long> left = get_subset_sums(0, n / 2 - 1);
	vector<long long> right = get_subset_sums(n / 2, n - 1);

	sort(left.begin(), left.end());
	sort(right.begin(), right.end());

	long long ans = 0;
	for(auto el:right) {
		auto low_iterator = lower_bound(left.begin(), left.end(), x - el);
		auto high_iterator = upper_bound(left.begin(), left.end(), x - el);
		int start_idx = low_iterator - left.begin();
		int end_idx = high_iterator - left.begin();
		ans += end_idx - start_idx;
	}

	cout << ans;

	return 0;
}
