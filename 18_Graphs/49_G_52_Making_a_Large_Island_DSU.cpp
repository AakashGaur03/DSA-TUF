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

bool isValid(int adjRow, int adjCol, int n) {
  return adjRow >= 0 && adjRow < n && adjCol >= 0 && adjCol < n;
}

int maxConnection(vector<vector<int>> &grid) {
  int n = grid.size(); // It is an Square matrix so no need to get m

  DisjointSet ds(n * n);
  // Step 1 Connect All Existing Components
  for (int row = 0; row < n; row++) {
    for (int col = 0; col < n; col++) {
      if (grid[row][col] == 0) {
        continue;
      }
      vector<int> dr = {-1, 0, 1, 0};
      vector<int> dc = {0, -1, 0, 1};

      for (int i = 0; i < 4; i++) {
        int adjr = row + dr[i];
        int adjc = col + dc[i];

        if (isValid(adjr, adjc, n) && grid[adjr][adjc] == 1) {
          int nodeNumber = row * n + col;
          int adjNodeNumber = adjr * n + adjc;
          ds.unionBySize(nodeNumber, adjNodeNumber);
        }
      }
    }
  }

  // Step 2 Covnert 0s to 1s
  int maxi = 0;
  for (int row = 0; row < n; row++) {
    for (int col = 0; col < n; col++) {
      if (grid[row][col] == 1) {
        continue;
      }

      vector<int> dr = {-1, 0, 1, 0};
      vector<int> dc = {0, -1, 0, 1};
      set<int> components;
      for (int i = 0; i < 4; i++) {
        int adjr = row + dr[i];
        int adjc = col + dc[i];

        if (isValid(adjr, adjc, n)) {
          if (grid[adjr][adjc] == 1) {
            int adjNodeNumber = adjr * n + adjc;
            components.insert(ds.findUPar(adjNodeNumber));
          }
        }
      }
      int sizeTotal = 1; // Start from 1 size as we are converting 0 to 1
      for (auto it : components) {
        sizeTotal += ds.size[it];
      }
      maxi = max(maxi, sizeTotal);
    }
  }
  // If all are Ones
  for (int cellNo = 0; cellNo < n * n; cellNo++) {
    maxi = max(maxi, ds.size[ds.findUPar(cellNo)]);
  }

  return maxi;
}

int main() {

  cout << "49 G 52 Making a Large Island DSU" << endl;

  // You are given a square binary grid.
  // A grid is considered binary if every value in the grid is either 1 or 0.

  // You can change at most one cell in the grid from 0 to 1.
  // You need to find the largest group of connected  1's.

  // Two cells are said to  be connected if both are adjacent(top, bottom, left,
  // right) to each other
  //  and both have the same value.

  // Refer 49_G_52_Making_a_Large_Island_DSU_1 and
  // 49_G_52_Making_a_Large_Island_DSU_2

  // In a matric we represent Matrix in Cell Numbers so we can use Disjoint Set
  // so as done in last File too each cell number will be represented as
  // (row * m) + col

  // 49_G_52_Making_a_Large_Island_DSU_3
  // keeps all the component and unionBySize helps us keep the size of Component
  // So when we will be Converting 0 to 1s then we already have sizes of the
  // components

  vector<vector<int>> grid = {{1, 0}, {0, 1}};

  cout << maxConnection(grid) << endl;

  return 0;
}