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

int solve(int n, vector<vector<int>> &edges) {
  DisjointSet ds(n);
  int cntExtra = 0;
  for (auto it : edges) {
    int u = it[0];
    int v = it[1];

    if (ds.findUPar(u) == ds.findUPar(v)) {
      cntExtra++;
    } else {
      ds.unionBySize(u, v);
    }
  }

  int connectedComp = 0;

  for (int i = 0; i < n; i++) {
    if (ds.findUPar(i) == i) {
      connectedComp++;
    }
  }

  int ans = connectedComp - 1;

  if (cntExtra >= ans) {
    return ans;
  } else {
    return -1;
  }
}
int main() {

  cout << "46 G 49 Number of Operations to Make Network Connected DSU" << endl;

  // Connecting the graph
  //  You are given a graph with n vertices (0 to n-1) and m edges. You can
  //  remove one edge from anywhere and add that edge between any two vertices
  //  in one operation.
  // Find the minimum number of operations that will be required to connect the
  // graph. If it is not possible to connect the graph, return -1.

  // So for N compnents we need N-1 Edges to make it connected
  // Refer 46_G_49_Number_of_Operations_to_Make_Network_Connected_DSU_1

  // So we need to just need to find the number of Components and then check if
  // there are extra edges
  // SO Ans is number of component - 1 if extraedges is greater than ans else -1

  // we will see here if any node have same Ultimate Parent then that Node is
  // extra
  // So Number of Components we can check if any nodes Parent is itself then it
  // is a separate Component as we also saw in
  // 45_G_48_Number_of_Provinces_Disjoint_Set

  int n = 4;

  vector<vector<int>> edges = {{0, 1}, {0, 2}, {1, 2}};

  cout << solve(n, edges);

  return 0;
}