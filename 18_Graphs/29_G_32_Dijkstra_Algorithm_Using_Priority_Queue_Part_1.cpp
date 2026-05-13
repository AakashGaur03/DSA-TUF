#include <bits/stdc++.h>
using namespace std;

// S is Source
vector<int> dijkstra(int V, vector<vector<vector<int>>> &adj, int S) {
  //  E is Edges
  // V is Number of nodes
  // TC O(E log V)
  // SC O(V + E)
  // Declared Minimum Heap
  priority_queue<pair<int, int>, vector<pair<int, int>>,
                 greater<pair<int, int>>>
      pq;

  vector<int> dist(V, INT_MAX);
  dist[S] = 0;
  pq.push({0, S});

  while (!pq.empty()) {
    int dis = pq.top().first;
    int node = pq.top().second;
    pq.pop();

    for (auto it : adj[node]) {
      int edgeWeight = it[1];
      int adjNode = it[0];

      if (dis + edgeWeight < dist[adjNode]) {
        dist[adjNode] = dis + edgeWeight;
        pq.push({dist[adjNode], adjNode});
      }
    }
  }

  return dist;
}

int main() {
  cout << "29 G 32 Dijkstra Algorithm Using Priority Queue Part 1" << endl;

  // NOTE Dijkstra Doeesnt works with Negative Weights

  // Important Algo for Shortest Path Problems

  // What Does the Algorithm Means

  // we will be given a source node
  // So from Source Node we have to find the shortest Distance to every other
  // node

  // It can be Implemented using PQ (Priority Queue) or Set
  // In this we wiil cover PQ
  // Priority Queue Takes More time in next we will cover Set

  // Let get started
  // In Adj List we will store Node and its weight
  // We will also have a min-heap DS that stores { distace , node }
  // min heap means Shorter Distance will be at top if Distance is same then
  // shorter Node will be at top

  // In distance array initialize it with infinity
  // for the First case that is from source to source set it to 0

  // Push Data one by one in min-heap
  // take that one from heap check where we can traverse if the path is short
  // update in Distance array

  // Repeat Steps until all covered

  // WHY Dijkstra Doeesnt works with Negative Weights
  // Because we go Back and forth in this
  // So Assume

  // 0  -------  1 and there weight is -2

  // So we will stuck in a infinte Loop going back and foth between 0 and 2 as 0
  // , -2 , -4 ,-6 .... as distance always Decreases
  // So it doesnt works with Negative weights

  int V = 3;

  // Adjacency List
  vector<vector<vector<int>>> adj(V);

  // 0 -> 1 (1)
  // 0 -> 2 (6)
  adj[0].push_back({1, 1});
  adj[0].push_back({2, 6});

  // 1 -> 2 (3)
  adj[1].push_back({2, 3});

  int S = 0;

  vector<int> ans = dijkstra(V, adj, S);

  for (int i = 0; i < V; i++) {
    cout << "Distance from Source to " << i << " is " << ans[i] << endl;
  }

  return 0;
}

// Why Priority Queue and not normal Queue ?

// We can still get the correct answer using Queue
// but it will take much more operations.

// Queue processes nodes in FIFO order
// not based on shortest distance.

// Priority Queue always processes
// the node having the smallest distance first.

// Because of this, shorter paths are explored earlier
// and unnecessary relaxations are reduced.

// So Dijkstra becomes efficient using Min Heap (Priority Queue).

// BFS uses Queue because every edge has equal weight.
// Dijkstra uses Priority Queue because edge weights can vary.