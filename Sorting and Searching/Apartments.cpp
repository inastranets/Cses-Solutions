#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m, k;
	cin >> n >> m >> k;
	vector<int> applicant(n);
	vector<int> apartment(m);

	for(int &size : applicant)
		cin >> size;

	for(int &size : apartment)
		cin >> size;

	sort(applicant.begin(), applicant.end());
	sort(apartment.begin(), apartment.end());

	int j = 0, ans = 0;
	for(int i = 0; i < n; ++i) {
		while(j < m && apartment[j] + k < applicant[i]) {
			++ j;
		}

		if(abs(apartment[j] - applicant[i]) <= k) { 
			++ ans; 
			++ j; 
		}
	}

	cout << ans;
	return 0;
}
