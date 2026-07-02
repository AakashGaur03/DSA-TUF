#include <bits/stdc++.h>
using namespace std;

int timer = 0;

void dfs(int node, int parent, vector<int> &vis, vector<int> &tin,
         vector<int> &low, vector<int> &mark, vector<vector<int>> &adj) {
  vis[node] = 1;
  tin[node] = low[node] = timer;
  timer++;
  int child = 0;
  for (auto it : adj[node]) {
    if (it == parent) {
      continue;
    }

    if (!vis[it]) {
      dfs(it, node, vis, tin, low, mark, adj);
      low[node] = min(low[node], low[it]);
      if (low[it] >= tin[node] && parent != -1) {
        mark[node] = 1;
      }
      child++;
    } else {
      low[node] = min(low[node], tin[it]);
    }
  }

  if (child > 1 && parent == -1) {
    // Checking Starting point
    mark[node] = 1;
  }
}

vector<int> articulationPoints(int n, vector<vector<int>> &adj) {
  vector<int> vis(n, 0);
  vector<int> tin(n);
  vector<int> low(n);
  vector<int> mark(n, 0);

  for (int i = 0; i < n; i++) {
    if (!vis[i]) {
      dfs(i, -1, vis, tin, low, mark, adj);
    }
  }

  vector<int> ans;
  for (int i = 0; i < n; i++) {
    if (mark[i] == 1) {
      // means Articulation Point
      ans.push_back(i);
    }
  }
  if (ans.size() == 0) {
    return {-1};
  } else {
    return ans;
  }
}

int main() {
  cout << "53 G 56 Articulation Point in Graph" << endl;
  // Articulation Point means nodes on whose removal the graph breaks into
  // multiple component

  // Ex Refer 53_G_56_Articulation_Point_in_Graph_1 In the image only 0 and 2
  // are the Nodes on whose removal Graph breaks into multiple component

  // Prerequisite
  // 52_G_55_Bridges_in_Graph_Using_Tarjan_Algorithm_of_time_in_and_low_time

  // time[] -> DFS time insertion (Store the time of insertion during DFS)
  // low[] -> min lowest time insertion of all adjacent nodes apart from
  // parent and visited Node (Extended Version)

  // And for Starting Point to be Articulation Point we dont apply the formula
  // as it fails for Starting Point we simply check if it has multiple Child
  // then it is Articulation Point else Not

  //   Given an undirected connected graph with V vertices and adjacency list
  //   adj. You are required to find all the vertices removing which (and
  //   edges through it) disconnects the graph into 2 or more components and
  //   return it in sorted manner.
  // Note: Indexing is zero-based i.e nodes numbering from (0 to V-1). There
  // might be loops present in the graph.

  // You don't need to read or print anything. Your task is to complete the
  // function articulationPoints() which takes V and adj as input parameters
  // and returns a list containing all the vertices removing which turn the
  // graph into two or more disconnected components in sorted order. If there
  // are no such vertices then returns a list containing -1.

  int V = 5;

  vector<vector<int>> adj(V);

  auto addEdge = [&](int u, int v) {
    adj[u].push_back(v);
    adj[v].push_back(u);
  };

  addEdge(0, 1);
  addEdge(1, 2);
  addEdge(2, 0);
  addEdge(1, 3);
  addEdge(3, 4);

  vector<int> ans = articulationPoints(V, adj);

  cout << "Articulation Points: ";
  for (int x : ans) {
    cout << x << " ";
  }
  cout << endl;

  //   0
  //  / \
  // 1---2
  // |
  // 3
  // |
  // 4

  return 0;
}