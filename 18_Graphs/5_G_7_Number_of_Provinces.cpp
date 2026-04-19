#include <bits/stdc++.h>
using namespace std;

void dfs(int node, vector<vector<int>> &adjLs, vector<int> &vis) {
  vis[node] = 1;
  // traverse all its neighbours
  for (auto it : adjLs[node]) {
    if (!vis[it]) {
      dfs(it, adjLs, vis);
    }
  }
}

int numberOfProvinces(int V, vector<vector<int>> &adjMat) {
  // TC O(N) Outer Loop  + (V + 2E) Inner Loop
  // SC O(N) visited Array + O(N) Stack Space

  vector<int> vis(V, 0);
  int cnt = 0;
  vector<vector<int>> adjLs(V);

  // --------------------------------------------------------
  // GENERIC CODE
  //  If we are given AdJ matrix then we can convert it to Adj List
  for (int i = 0; i < V; i++) {
    for (int j = 0; j < V; j++) {
      if (adjMat[i][j] == 1 && i != j) {
        adjLs[i].push_back(j);
      }
    }
  }
  // It still behaves like an undirected graph because:
  // Because we are scanning the full matrix:
  // Matrix has both adjMat[i][j] and adjMat[j][i]
  // So both directions eventually get added
  // OR
  // we can reduce work by half:
  // for (int i = 0; i < V; i++) {
  //   for (int j = i + 1; j < V; j++) {
  //     if (adjMat[i][j] == 1) {
  //       adjLs[i].push_back(j);
  //       adjLs[j].push_back(i);
  //     }
  //   }
  // }

  // --------------------------------------------------------

  // This will only cover one Province
  // dfs(index, adjLs, vis);
  for (int i = 0; i < V; i++) {
    if (!vis[i]) {
      cnt++;
      dfs(i, adjLs, vis);
    }
  }

  return cnt;
}

int main() {
  cout << "5 G 7 Number of Provinces" << endl;
  // Provinces are Components that are connected to themselves correctly but
  // dont have interactions with other nodes

  //       0 - 1         3-4       6
  //          /           /        |
  //         2           5         7

  // SO above is a single graph.
  // But as we can se 1 can is rechable by 2 and 3 only
  // Means 1 2 3 are only reachable within them so they are a Province

  // Similary 4 5 6 is a Province
  // and 7 8 is a Province

  int V = 8;

  // Create adjacency matrix (0-based)
  vector<vector<int>> adjMat(V, vector<int>(V, 0));

  // -------- Province 1: 0-1-2 --------
  adjMat[0][1] = adjMat[1][0] = 1;
  adjMat[1][2] = adjMat[2][1] = 1;

  // -------- Province 2: 3-4-5 --------
  adjMat[3][4] = adjMat[4][3] = 1;
  adjMat[4][5] = adjMat[5][4] = 1;

  // -------- Province 3: 6-7 --------
  adjMat[6][7] = adjMat[7][6] = 1;

  // Optional: self connections (not required because you check i != j)
  for (int i = 0; i < V; i++) {
    adjMat[i][i] = 1;
  }

  int result = numberOfProvinces(V, adjMat);
  cout << "Number of Provinces: " << result << endl;

  return 0;
}