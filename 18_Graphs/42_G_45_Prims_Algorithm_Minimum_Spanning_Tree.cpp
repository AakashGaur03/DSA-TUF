#include <bits/stdc++.h>
using namespace std;

int spanningTree(int V, vector<vector<pair<int, int>>> adj) {
  // TC O(E logV)
  // SC (V+E)
  priority_queue<pair<int, int>, vector<pair<int, int>>,
                 greater<pair<int, int>>>
      pq;
  vector<int> vis(V, 0);
  pq.push({0, 0});
  int sum = 0;
  while (!pq.empty()) {
    auto it = pq.top();
    pq.pop();
    int weight = it.first;
    int node = it.second;

    if (vis[node] == 1)
      continue;
    // otherwise when we add it to MST mark as visited
    vis[node] = 1;
    sum += weight;

    for (auto iter : adj[node]) {
      int adjNode = iter.first;
      int edgeWeight = iter.second;

      if (!vis[adjNode]) {
        pq.push({edgeWeight, adjNode});
      }
    }
  }

  return sum;
}
int main() {

  cout << "42_G_45_Prims_Algorithm_Minimum_Spanning_Tree" << endl;

  // Prim's Algorithm, Algo to find us MST (discussed in
  // 41_G_44_Minimum_Spanning_Tree_Theory)

  // Prim's Algorithm Helps us to find the Summation of Wights that is MST
  // weight as well as edges (means tree)too

  // For Initial Config we will have a
  // visited array with everything as 0
  // and a PQ that contains {weight,node,parent}
  // a sum that keeps summation and MST array that keeps edges

  // As in the PQ we are keeping our first element as wt so minimum Weight will
  // always be taken and when all have been visited we will be sure that
  // whatever is there in PQ availabe will be surely greater or equal than the
  // existing one so we skip when that node from PQ

  // Intution is simply Greedy

  // we will start with any node lets start from 0 so {0,0,-1}
  // parent is -1 because no parent of Starting Node so far

  // Also we need parent only if we need to return the MST if we have to just
  // find the sum we can simply store {wt,node}

  // Given a weighted, undirected, and connected graph with V vertices and E
  // edges, your task is to find the sum of the weights of the edges in the
  // Minimum Spanning Tree (MST) of the graph. The graph is provided as a list
  // of edges, where each edge is represented as [u, v, w], indicating an edge
  // between vertex u and vertex v with edge weight w.

  int V = 5;

  vector<vector<pair<int, int>>> adj(V);

  // Undirected Weighted Graph

  adj[0].push_back({1, 2});
  adj[1].push_back({0, 2});

  adj[0].push_back({3, 6});
  adj[3].push_back({0, 6});

  adj[1].push_back({2, 3});
  adj[2].push_back({1, 3});

  adj[1].push_back({3, 8});
  adj[3].push_back({1, 8});

  adj[1].push_back({4, 5});
  adj[4].push_back({1, 5});

  adj[2].push_back({4, 7});
  adj[4].push_back({2, 7});

  cout << "MST Weight : " << spanningTree(V, adj) << endl;
  return 0;
}