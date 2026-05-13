#include <bits/stdc++.h>
using namespace std;

// S is Source
vector<int> dijkstra(int V, vector<vector<vector<int>>> &adj, int S) {
  //  E is Edges
  // V is Number of nodes
  // TC O(E log V)
  // SC O(V + E)
  // Declared Minimum Heap
  set<pair<int, int>> st;
  vector<int> dist(V, INT_MAX);
  dist[S] = 0;
  st.insert({0, S});

  while (!st.empty()) {
    auto it = *(st.begin());
    int dis = it.first;
    int node = it.second;
    st.erase(it);

    for (auto it : adj[node]) {
      int edgeWeight = it[1];
      int adjNode = it[0];

      if (dis + edgeWeight < dist[adjNode]) {
        if (dist[adjNode] != INT_MAX) {
          st.erase({dist[adjNode], adjNode});
        }
        dist[adjNode] = dis + edgeWeight;
        st.insert({dist[adjNode], adjNode});
      }
    }
  }

  return dist;
}

int main() {
  cout << "30 G 33 Dijkstra Algorithm Using Set Part 2" << endl;
  // Extension of 29_G_32_Dijkstra_Algorithm_Using_Priority_Queue_Part_1
  // In this video we will be using Set
  // Set stores only uniquw value and in ascending order means Smallest at the
  // top
  // Basic Goal of Set is to erase the already exisitng path and getting a
  // shorter one so to erase the previous one in PQ we cant do that so we were
  // perfoming iterations on that repetitive values too
  // There wont be much differnece in TC as st.erase will also take log N and
  // then we are saving on some future operations

  // So there is no Best among PQ and Set both are they ways of solving the
  // issue
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

// | Priority Queue             | Set                          |
// | -------------------------- | ---------------------------- |
// | Cannot remove old distance | Can erase old distance       |
// | Duplicate entries possible | Only latest shortest kept    |
// | Simpler implementation     | Slightly cleaner processing  |
// | More extra iterations      | Fewer unnecessary iterations |
