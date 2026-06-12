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

bool isValid(int adjRow, int adjCol, int n, int m) {
  return adjRow >= 0 && adjRow < n && adjCol >= 0 && adjCol < m;
}

vector<int> numOfIslands(int n, int m, vector<vector<int>> &operators) {
  DisjointSet ds(n * m);
  vector<vector<int>> vis(n, vector<int>(m, 0));
  int cnt = 0;

  vector<int> ans;
  for (auto it : operators) {
    int row = it[0];
    int col = it[1];

    if (vis[row][col] == 1) {
      ans.push_back(cnt);
      continue;
    }
    vis[row][col] = 1;
    cnt++;

    vector<int> dr = {-1, 0, 1, 0};
    vector<int> dc = {0, 1, 0, -1};

    for (int ind = 0; ind < 4; ind++) {
      int adjRow = row + dr[ind];
      int adjCol = col + dc[ind];

      if (isValid(adjRow, adjCol, n, m)) {
        if (vis[adjRow][adjCol] == 1) {
          int nodeNumber = row * m + col;
          int adjNodeNumber = adjRow * m + adjCol;
          if (ds.findUPar(nodeNumber) != ds.findUPar(adjNodeNumber)) {
            cnt--;
            ds.unionBySize(nodeNumber, adjNodeNumber);
          }
        }
      }
    }
    ans.push_back(cnt);
  }

  return ans;
}

int main() {

  cout << "48 G 51 Number of Islands II Online Queries DSU" << endl;

  // Refer
  // 48_G_51_Number_of_Islands_II_Online_Queries_DSU_1
  // 48_G_51_Number_of_Islands_II_Online_Queries_DSU_2
  // So we need to return the Number of Islands at each stage

  //   Number of islands II

  // Given n, m denoting the row and column of the 2D matrix, and an array A of
  // size k denoting the number of operations. Matrix elements are 0 if there is
  // water or 1 if there is land. Originally, the 2D matrix is all 0 which means
  // there is no land in the matrix.

  // The array has k operator(s) and each operator has two integers A[i][0],
  // A[i][1] means that you can change the cell matrix[A[i][0]][A[i][1]] from
  // sea to island. Return how many islands are there in the matrix after each
  // operation.

  // The directions to check for the island are up, down, right, left. The
  // answer array will be of size k.

  // Example 1

  // Input: n = 4, m = 5, k = 4, A = [[1,1],[0,1],[3,3],[3,4]]

  // Output: [1, 1, 2, 2]

  // Explanation: The following illustration is the representation of the
  // operation:

  // Example 2

  // Input: n = 4, m = 5, k = 12, A =
  // [[0,0],[0,0],[1,1],[1,0],[0,1],[0,3],[1,3],[0,4], [3,2], [2,2],[1,2],
  // [0,2]]

  // Output: [1, 1, 2, 1, 1, 2, 2, 2, 3, 3, 1, 1]

  // Explanation: If we follow the process like in example 1, we will get the
  // above result.

  int n = 4, m = 5;

  vector<vector<int>> operators = {{1, 1}, {0, 1}, {3, 3}, {3, 4}};

  vector<int> ans = numOfIslands(n, m, operators);

  for (int x : ans) {
    cout << x << " ";
  }
  cout << endl;

  return 0;
}