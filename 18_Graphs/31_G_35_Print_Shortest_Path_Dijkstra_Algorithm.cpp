#include <bits/stdc++.h>
using namespace std;

// n is number of nodes
// m is number of edges
vector<int> dijkstra(int n, vector<vector<int>> &edges, int m) {
  // TC O(E log V) + O(N)

  vector<vector<pair<int, int>>> adj(n + 1);
  for (auto it : edges) {
    int u = it[0];
    int v = it[1];
    int wt = it[2];

    adj[u].push_back({v, wt});
    adj[v].push_back({u, wt});
  }

  priority_queue<pair<int, int>, vector<pair<int, int>>,
                 greater<pair<int, int>>>
      pq;
  vector<int> dist(n + 1, INT_MAX);
  vector<int> parent(n + 1);
  for (int i = 0; i <= n; i++) {
    parent[i] = i;
  }

  dist[1] = 0;
  pq.push({0, 1});

  while (!pq.empty()) {
    int dis = pq.top().first;
    int node = pq.top().second;
    pq.pop();

    for (auto it : adj[node]) {
      int adjNode = it.first;
      int edgeWeight = it.second;

      if (dis + edgeWeight < dist[adjNode]) {
        dist[adjNode] = dis + edgeWeight;
        pq.push({dis + edgeWeight, adjNode});
        parent[adjNode] = node;
      }
    }
  }

  if (dist[n] == INT_MAX) {
    return {-1};
  }

  // Backtracks the Parent Means acc to shorter distance checks where did Parent
  // came from and add them in Answer
  // TC O(N)
  vector<int> path;
  int node = n;
  while (parent[node] != node) {
    path.push_back(node);
    node = parent[node];
  }
  path.push_back(1);
  reverse(path.begin(), path.end());

  return path;
}

int main() {
  cout << "31 G 35 Print Shortest Path Dijkstra Algorithm" << endl;

  //   You are given a weighted undirected graph with n vertices numbered from 1
  //   to n and m edges along with their weights. Find the shortest path between
  //   vertex 1 and vertex n. Each edge is given as {a, b, w}, denoting an edge
  //   between vertices a and b with weight w.

  // Basically This Says to print the Shortest Path not just FInd it
  // Src is always 1 and Destination is always N
  // So we need to Find the shortest Path from 1 to N

  // So in Dijkstra Algorithm we will remember where we are coming from

  // So with PQ distance array we will also keep a Parent Array that will help
  // us memoize where we came from

  int n = 5;
  int m = 6;

  // {u, v, weight}
  vector<vector<int>> edges = {{1, 2, 2}, {2, 5, 5}, {2, 3, 4},
                               {1, 4, 1}, {4, 3, 3}, {3, 5, 1}};

  vector<int> ans = dijkstra(n, edges, m);

  cout << "Answer: ";

  for (auto it : ans) {
    cout << it << " ";
  }

  return 0;
}
