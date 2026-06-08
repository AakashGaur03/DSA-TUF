#include <bits/stdc++.h>
using namespace std;

class DisjointSet {
  vector<int> rank, parent;

public:
  DisjointSet(int n) {
    rank.resize(n + 1, 0); // Resize and everything is 0 // Works for both 0
                           // based and 1 based indexing
    parent.resize(n + 1);
    for (int i = 0; i <= n; i++) {
      parent[i] = i; // In Parent Initally everything is set as themselves
    }
  }

  int findUPar(int node) { // Ultimate Parent
    if (node == parent[node]) {
      return node;
    }

    // return findUPar(parent[node]); // Normal Recursion

    return parent[node] = findUPar(parent[node]); // Path Compression
  }

  void unionByRank(int u, int v) {
    int ulp_u = findUPar(u);
    int ulp_v = findUPar(v);

    if (ulp_u == ulp_v) {
      // Already belong to same component
      return;
    }

    if (rank[ulp_u] < rank[ulp_v]) {
      // Means u gets attached to v as v is greater
      parent[ulp_u] = ulp_v;
    } else if (rank[ulp_v] < rank[ulp_u]) {
      // Means v gets attached to u as u is greater
      parent[ulp_v] = ulp_u;
    } else {
      // rank[ulp_v] == rank[ulp_u]
      // We can attach it anywhere But need to update Rank too
      parent[ulp_v] = ulp_u;
      rank[ulp_u]++;
    }
  }
};

int numberOfProvinces(int V, vector<vector<int>> &adjMat) {
  // TC O(V^2 * α(V)) = O(V^2)
  // SC O(V)

  DisjointSet ds(V);

  for (int i = 0; i < V; i++) {
    for (int j = 0; j < V; j++) {
      if (adjMat[i][j] == 1) {
        ds.unionByRank(i, j);
      }
    }
  }
  int cnt = 0;
  for (int i = 0; i < V; i++) {
    if (ds.findUPar(i) == i) {
      cnt++;
    }
  }

  return cnt;
}

int main() {

  cout << "45 G 48 Number of Provinces Disjoint Set" << endl;

  //   There are n cities. Some of them are connected, while some are not. If
  //   city a is connected directly with city b, and city b is connected
  //   directly with city c, then city a is connected indirectly with city c.

  // A province is a group of directly or indirectly connected cities and no
  // other cities outside of the group.

  // You are given an n x n matrix isConnected where isConnected[i][j] = 1 if
  // the ith city and the jth city are directly connected, and
  // isConnected[i][j] = 0 otherwise.

  // Return the total number of provinces.

  // We have covered same problem in 5_G_7_Number_of_Provinces For
  // understanding Disjoint Set we will cover it here too

  // We will simply count number of differnt Ultimate Parents Present
  // or we can also say that when a node is equal to its ultimate present then
  // it is a differnt component or differnt Provinces

  vector<vector<int>> adjMat = {{1, 1, 0}, {1, 1, 0}, {0, 0, 1}};

  int V = adjMat.size();

  cout << "Number of Provinces: " << numberOfProvinces(V, adjMat) << endl;

  return 0;

  return 0;
}