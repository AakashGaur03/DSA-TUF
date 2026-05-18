#include <bits/stdc++.h>
using namespace std;

int minimumMultiplications(vector<int> &arr, int start, int end, int mod) {
  // TC O(mod*N)
  // SC O(mod)
  queue<pair<int, int>> q;
  // {start,steps}
  q.push({start, 0});
  vector<int> dist(mod, INT_MAX);
  dist[start] = 0;
  if (start == end)
    return 0;
  while (!q.empty()) {
    auto iter = q.front();
    int node = iter.first;
    int steps = iter.second;
    q.pop();

    for (auto multiplier : arr) {
      int num = (multiplier * node) % mod;
      if (steps + 1 < dist[num]) {
        dist[num] = steps + 1;
        if (num == end) {
          return steps + 1;
        }
        q.push({num, steps + 1});
      }
    }
  }
  return -1;
}

int main() {
  cout << "35 G 39 Minimum Multiplications to Reach End" << endl;

  //   Given two integers, start and end, along with an array of integers arr[].
  //   In one operation, you can multiply the current value by any element from
  //   arr[], and then take the result modulo 1000 to obtain a new value.

  // Find the minimum steps in which end can be achieved starting from start. If
  // it is not possible to reach end, then return -1.

  // This is slightly tricky but simple Dijkstra Implementation
  // Tricky Part is identifying Dijkstra and distance array
  // Distance array will be 0 - 9999

  vector<int> arr = {2, 5, 7};

  int start = 3;
  int end = 30;
  int mod = 100000;

  int ans = minimumMultiplications(arr, start, end, mod);

  cout << "Minimum Steps Required : " << ans << endl;

  return 0;

  return 0;
}
