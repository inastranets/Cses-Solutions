#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  vector<pair<int,int>> task(n);

  for(auto& [duration, deadline] : task)
    cin >> duration >> deadline;

  sort(task.begin(), task.end());

  long long finish_time = 0, best = 0;
  for(auto& [duration, deadline] : task) {
    finish_time += duration;
    best += deadline - finish_time;
  }

  cout << best;

  return 0;
}
