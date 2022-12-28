#include <bits/stdc++.h>

using namespace std;

int main() {
	int n; 
	cin >> n;
	long long sum = 1ll * n * (n + 1) / 2; // 1 + 2 + 3 + .. + n
	// if sum / 2 is odd we cannot divide
	// else every set will be have sum / 4
        if(sum & 1) {
		cout << "NO";
	} else {
		cout << "YES\n";
		
		set<long long> set1, set2;
		
		// add every number from [1,n] into first set, after will be erase and add to second set
		for(int x = 1; x <= n; ++ x)
			set1.insert(x);
		
		sum/=2;
		
		int target = n;
		
		while(!set1.count(sum)) {
			set2.insert(target);
			set1.erase(target);
			sum -= target;	
			--target;
		}
		// found number that has not yet been added to second set
		set1.erase(sum);
		set2.insert(sum);


		cout << set1.size() << '\n';
		
		for(int out:set1)
			cout << out << ' ';
		
		cout << set2.size() << '\n';

		for(int out:set2)
			cout << out << ' ';
	}
	return 0;
}
