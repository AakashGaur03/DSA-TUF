#include <bits/stdc++.h>
using namespace std;

int countPaths(int n, vector<vector<int>> &roads) {
  vector<vector<pair<int, int>>> adj(n);

  for (auto it : roads) {
    // Undirected Graph
    adj[it[0]].push_back({it[1], it[2]});
    adj[it[1]].push_back({it[0], it[2]});
  }

  // {dist,node}
  priority_queue<pair<int, int>, vector<pair<int, int>>,
                 greater<pair<int, int>>>
      pq;

  vector<int> dist(n, INT_MAX);
  dist[0] = 0;
  vector<int> ways(n, 0);
  ways[0] = 1;
  pq.push({0, 0});
  int mod = (int)(1e9 + 7); // cause asked answer in Modulo

  while (!pq.empty()) {
    auto it = pq.top();
    int dis = it.first;
    int node = it.second;
    pq.pop();

    for (auto iter : adj[node]) {
      int adjNode = iter.first;
      int edgeWeight = iter.second;

      // First time coming with Short distance
      if (dis + edgeWeight < dist[adjNode]) {
        dist[adjNode] = dis + edgeWeight;
        pq.push({dis + edgeWeight, adjNode});
        ways[adjNode] = ways[node];
      } else if (dis + edgeWeight == dist[adjNode]) {
        ways[adjNode] = (ways[adjNode] + ways[node]) % mod;
      }
    }
  }

  return ways[n - 1] % mod;
}

int main() {
  cout << "36 G 40 Number of Ways to Arrive at Destination" << endl;

  // You are in a city that consists of n intersections numbered from 0 to n - 1
  // with bi-directional roads between some intersections. The inputs are
  // generated such that you can reach any intersection from any other
  // intersection and that there is at most one road between any two
  // intersections.

  // You are given an integer n and a 2D integer array roads where roads[i] =
  // [ui, vi, timei] means that there is a road between intersections ui and vi
  // that takes timei minutes to travel. You want to know in how many ways you
  // can travel from intersection 0 to intersection n - 1 in the shortest amount
  // of time.

  // Return the number of ways you can arrive at your destination in the
  // shortest amount of time. Since the answer may be large, return it modulo
  // 109 + 7.

  // Refer 36_G_40_Number_of_Ways_to_Arrive_at_Destination_1

  int n = 7;

  vector<vector<int>> roads = {{0, 6, 7}, {0, 1, 2}, {1, 2, 3}, {1, 3, 3},
                               {6, 3, 3}, {3, 5, 1}, {6, 5, 1}, {2, 5, 1},
                               {0, 4, 5}, {4, 6, 2}};

  cout << "Number of Ways : " << countPaths(n, roads);

  return 0;
}
