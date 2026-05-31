#include <bits/stdc++.h>
using namespace std;

class DisjointSet {
  vector<int> parent, size;

public:
  DisjointSet(int n) {
    parent.resize(n + 1);
    size.resize(n + 1);
    for (int i = 0; i <= n; i++) {
      parent[i] = i; // In Parent Initally everything is set as themselves
      size[i] = 1;   // In Size Initally everything is set as 1
    }
  }

  int findUPar(int node) { // Ultimate Parent
    if (node == parent[node]) {
      return node;
    }

    // return findUPar(parent[node]); // Normal Recursion

    return parent[node] = findUPar(parent[node]); // Path Compression
  }

  void unionBySize(int u, int v) {
    int ulp_u = findUPar(u);
    int ulp_v = findUPar(v);

    if (ulp_u == ulp_v) {
      // Already belong to same component
      return;
    }

    if (size[ulp_u] < size[ulp_v]) {
      // Means u gets attached to v as v is greater
      parent[ulp_u] = ulp_v;
      // when we attach to v so size of V will be increased by U
      size[ulp_v] += size[ulp_u];
    } else {
      // rank[ulp_v] == rank[ulp_u] || rank[ulp_v] < rank[ulp_u]
      // We can attach v to u in both cases
      parent[ulp_v] = ulp_u;
      // when we attach to U so size of U will be increased by V
      size[ulp_u] += size[ulp_v];
    }
  }
};

int spanningTree(int V, vector<vector<vector<int>>> &adj) {
  // TC (N+E) + (M Log M) + (2* M * 4 * alpha) = // O(E log E + E α(V))
  // SC O(M)
  vector<pair<int, pair<int, int>>> edges;
  // TC O(N+E)
  for (int i = 0; i < V; i++) {
    for (auto it : adj[i]) {
      int adjNode = it[0];
      int wt = it[1];
      int node = i;

      edges.push_back({wt, {node, adjNode}});
    }
  }

  DisjointSet ds(V);
  // TC O(M Log M)
  sort(edges.begin(), edges.end());

  int mstWt = 0;
  // (2* M * 4 * alpha)
  for (auto it : edges) {
    int wt = it.first;
    int u = it.second.first;
    int v = it.second.second;

    if (ds.findUPar(u) != ds.findUPar(v)) {
      mstWt += wt;
      ds.unionBySize(u, v);
    }
  }

  return mstWt;
}
int main() {

  cout << "44 G 47 Kruskals Algorithm Minimum Spanning Tree" << endl;

  // Kruskals Algorithm helps us to find Minimum Spanning Tree(MST)
  // we can find Minimum Spanning Tree(MST) using Prism Algo also that we
  // discussed in 42_G_45_Prims_Algorithm_Minimum_Spanning_Tree But here we will
  // discuss how to do using Kruskals Algorithm

  // Inital Graph 44_G_47_Kruskals_Algorithm_Minimum_Spanning_Tree_1
  // Steps
  // 1) Sort All the Edges acc to weight
  // After Sorting it will look like
  // 44_G_47_Kruskals_Algorithm_Minimum_Spanning_Tree_2

  // So now we declare Disjoint Set using these nodes

  // So now what we will do is we will go Node by Node first check if they
  // belong to same parent using findUPar and if not then do unionByRank or
  // unionBySize and also add up the weight

  // So if thet exist in sameUPar then they are already connected and union will
  // help us connecting them and when we are adding the weights so if required
  // in quesiton we can all return the total weight of the MST too

  int V = 5;

  vector<vector<vector<int>>> adj(V);

  // 0 --1(2)
  adj[0].push_back({1, 2});
  adj[1].push_back({0, 2});

  // 0 --3(6)
  adj[0].push_back({3, 6});
  adj[3].push_back({0, 6});

  // 1 --2(3)
  adj[1].push_back({2, 3});
  adj[2].push_back({1, 3});

  // 1 --3(8)
  adj[1].push_back({3, 8});
  adj[3].push_back({1, 8});

  // 1 --4(5)
  adj[1].push_back({4, 5});
  adj[4].push_back({1, 5});

  // 2 --4(7)
  adj[2].push_back({4, 7});
  adj[4].push_back({2, 7});

  cout << "MST Weight = " << spanningTree(V, adj);

  /*

         2
   0 ------ 1
   |      / | \
 6 |    3   |5 \
   |  /     |   \
   3 ------ 2----4
      8      7
  */
  return 0;
}