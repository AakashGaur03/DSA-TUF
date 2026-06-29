#include <bits/stdc++.h>
using namespace std;

class DisjointSet {

public:
  vector<int> parent, size;
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

int maxRemove(vector<vector<int>> &stones, int n) {
  int maxRow = 0;
  int maxCol = 0;
  for (auto it : stones) {
    maxRow = max(maxRow, it[0]);
    maxCol = max(maxCol, it[1]);
  }
  DisjointSet ds(maxRow + maxCol + 1);
  unordered_map<int, int> stoneNodes;
  for (auto it : stones) {
    int nodeRow = it[0];
    int nodeCol = it[1] + maxRow + 1;
    ds.unionBySize(nodeRow, nodeCol);
    stoneNodes[nodeRow] = 1;
    stoneNodes[nodeCol] = 1;
  }

  int cnt = 0;
  for (auto it : stoneNodes) {
    if (ds.findUPar(it.first) == it.first) {
      cnt++;
    }
  }

  return n - cnt;
}
int main() {

  cout << "50 G 53 Most Stones Removed with Same Row or Column DSU" << endl;

  //   Given an 2D array of non-negative integers stones[][] where stones[i] =
  //   [xi , yi] represents the location of the ith stone on a 2D plane, the
  //   task is to return the maximum possible number of stones that you can
  //   remove.

  // A stone can be removed if it shares either the same row or the same column
  // as another stone that has not been removed.

  // Note: Each coordinate point may have at most one stone.

  // Intution
  // If we are somehow able to map them in Components then we can remove
  // (Component Size - 1) for each Component and in the end we can add
  // (Component1Size - 1) + (Component2Size - 1) + .... (ComponentNSize - 1)
  // (Component1Size + Component2Size + ... ComponentNSize) - 1 -1... -1
  // (Component1Size + Component2Size + ... ComponentNSize) - (1 +1... +1)
  // (Component1Size + Component2Size + ... ComponentNSize) = Number of Stones
  // So answer will also be
  // Number of Stones - Number of Components
  // Refer 50_G_53_Most_Stones_Removed_with_Same_Row_or_Column_DSU_1

  // Main Catch is How to get to Number of Components Because here we are not
  // taking Neighbours we have to consider Row and Cols as Components
  // Here we will consider rows and cols as Nodes in a Disjoint Set
  // Refer 50_G_53_Most_Stones_Removed_with_Same_Row_or_Column_DSU_2

  vector<vector<int>> stones = {{0, 0}, {0, 1}, {1, 0}, {1, 2}, {2, 1}, {2, 2}};

  int n = stones.size();

  cout << "Maximum stones that can be removed = " << maxRemove(stones, n)
       << endl;
  return 0;
}