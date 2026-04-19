#include <bits/stdc++.h>
using namespace std;

void dfs(int node, vector<vector<int>> &adj, vector<int> &vis,
         vector<int> &ls) {
  vis[node] = 1;
  ls.push_back(node);
  // traverse all its neighbours
  for (auto it : adj[node]) {
    if (!vis[it]) {
      dfs(it, adj, vis, ls);
    }
  }
}

vector<int> dfsOfGraph(int V, vector<vector<int>> &adj) {
  // TC O(N + 2E)
  // SC O(N) + O(N)
  vector<int> vis(V, 0);
  int start = 1;
  vector<int> ls;
  dfs(start, adj, vis, ls);
  return ls;
}

int main() {
  cout << "4 G 6 Depth First Search DFS" << endl;
  // Depth First Search
  // Here Level is acc to distance Gap 1 to Level 1

  // Starting point 1

  //        1
  //     /    \
  //    2      3  -  4
  //  /  \     |     |
  // 5    6    7  -  8

  // 1 2 5 6 3 7 8 4
  // 1 3 7 8 4 2 6 5

  // Starting point 3
  //        1
  //     /    \
  //    2      3  -  4
  //  /  \     |     |
  // 5    6    7  -  8

  // 3 4 8 7 1 2 5 6
  // Here there can be multiple DFS one 3 goes to 4 and then further
  // Second 3 goes to 7 and then further
  // Third 3 goes to 1 and then further
  // and within them also

  // We will use Recursion to implement it

  // We will iterate from 0 or 1 acc to graph till number of nodes
  // we will have a visited array and mark the intial point as 1 that is visited
  // then will check if the node is visisted if not then call the recursive
  // function on its adj list values and do same steps
  // Refer 4_G_6_Depth_First_Search_DFS_1
  // (NOTE IN IMG 3 should also be marked as VISITED)

  // So Adj List
  // 1 -> {2,3}
  // 2 -> {1,5,6 }
  // 3 -> {1,4,7}
  // 4 -> {3,8}
  // 5 -> {2}
  // 6 -> {2}
  // 7 -> {3,8}
  // 8 -> {4,7}

  int V = 9;
  vector<vector<int>> adj(V);

  // 1-based graph (index 0 unused)
  adj[1] = {2, 3};
  adj[2] = {1, 5, 6};
  adj[3] = {1, 4, 7};
  adj[4] = {3, 8};
  adj[5] = {2};
  adj[6] = {2};
  adj[7] = {3, 8};
  adj[8] = {4, 7};

  vector<int> result = dfsOfGraph(V, adj);

  for (auto x : result)
    cout << x << " ";

  return 0;
}