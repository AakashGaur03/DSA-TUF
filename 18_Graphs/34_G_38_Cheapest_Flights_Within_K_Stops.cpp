#include <bits/stdc++.h>
using namespace std;

int cheapestFligh(int n, vector<vector<int>> &flights, int src, int dst,
                  int K) {
  // TC O(E) = O(Number of Flights)
  vector<pair<int, int>> adj[n];
  for (auto it : flights) {
    adj[it[0]].push_back({it[1], it[2]});
  }
  queue<pair<int, pair<int, int>>> q;
  // {stops,{node,dist}}
  q.push({0, {src, 0}});
  vector<int> dist(n, INT_MAX);
  dist[src] = 0;

  while (!q.empty()) {
    auto it = q.front();
    q.pop();
    int stops = it.first;
    int node = it.second.first;
    int cost = it.second.second;

    if (stops > K) {
      continue;
    }

    for (auto iter : adj[node]) {
      int adjNode = iter.first;
      int edgeWeight = iter.second;

      if (cost + edgeWeight < dist[adjNode] && stops <= K) {
        dist[adjNode] = cost + edgeWeight;
        q.push({stops + 1, {adjNode, cost + edgeWeight}});
      }
    }
  }

  if (dist[dst] == INT_MAX) {
    return -1;
  } else {
    return dist[dst];
  }
}

int main() {
  cout << "34 G 38 Cheapest Flights Within K Stops" << endl;

  // There are n cities connected by some number of flights. You are given an
  // array flights where flights[i] = [fromi, toi, pricei] indicates that there
  // is a flight from city fromi to city toi with cost pricei.

  // You are also given three integers src, dst, and k, return the cheapest
  // price from src to dst with at most k stops. If there is no such route,
  // return -1.

  // We cant apply Dijkstra Algorithm here because there can be a scenario where
  // we want to reach in 2 steps but Dijkstra hold minimum distance for 3 steps
  // so even in 2 steps is possible to reach the destination we wont be able to
  // pick it up
  // so Instead of storing in terms of {dist,node,stops}
  // we will store {stops,node,dist} so we can consider acc to stops
  // and as stops are increasing in Unit steps we can use normal Queue too
  // instead of PQ

  int n = 4;

  vector<vector<int>> flights = {
      {0, 1, 100}, {1, 2, 100}, {2, 3, 100}, {0, 3, 500}};

  int src = 0;
  int dst = 3;
  int K = 1;

  int ans = cheapestFligh(n, flights, src, dst, K);

  cout << "Cheapest Flight Cost: " << ans << endl;

  return 0;
}
