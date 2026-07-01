#include <bits/stdc++.h>
using namespace std;

int timer = 1;

void dfs(int node, int parent, vector<int> &vis, vector<vector<int>> &adj,
         vector<int> &tin, vector<int> &low, vector<vector<int>> &bridges) {
  vis[node] = 1;
  tin[node] = low[node] = timer;
  timer++;

  for (auto it : adj[node]) {
    if (it == parent) {
      continue;
    }

    if (vis[it] == 0) {
      dfs(it, node, vis, adj, tin, low, bridges);
      low[node] = min(low[node], low[it]);

      if (low[it] > tin[node]) {
        bridges.push_back({it, node});
      }
    } else {
      low[node] = min(low[node], tin[it]);
    }
  }
}

vector<vector<int>> criticalConnections(int n,
                                        vector<vector<int>> &connections) {
  // TC O(V + 2E)
  // SC O(3N + V + 2E)
  vector<vector<int>> adj(n);

  for (auto it : connections) {
    adj[it[0]].push_back(it[1]);
    adj[it[1]].push_back(it[0]);
  }

  vector<int> vis(n, 0);
  vector<int> tin(n);
  vector<int> low(n);
  vector<vector<int>> bridges;

  for (int i = 0; i < n; i++) {
    if (!vis[i]) {
      dfs(i, -1, vis, adj, tin, low, bridges);
    }
  }
  return bridges;
}

int main() {

  cout << "52 G 55 Bridges in Graph Using Tarjan Algorithm of time in and low "
          "time"
       << endl;
  // Bridges in Graph means when we remove an edge an components breaks into 2
  // Components
  // Refer
  // 52_G_55_Bridges_in_Graph_Using_Tarjan_Algorithm_of_time_in_and_low_time_1
  // and
  // 52_G_55_Bridges_in_Graph_Using_Tarjan_Algorithm_of_time_in_and_low_time_2
  // 52_G_55_Bridges_in_Graph_Using_Tarjan_Algorithm_of_time_in_and_low_time_3

  // time[] -> DFS time insertion
  // low[] -> min lowest time insertion of all adjacent nodes apart from parent

  //   Critical Connections in a Network
  // There are n servers numbered from 0 to n - 1 connected by undirected
  // server-to-server connections forming a network where connections[i] = [ai,
  // bi] represents a connection between servers ai and bi. Any server can reach
  // other servers directly or indirectly through the network.

  // A critical connection is a connection that, if removed, will make some
  // servers unable to reach some other server.

  // Return all critical connections in the network in any order.

  int n = 4;

  vector<vector<int>> connections = {{0, 1}, {1, 2}, {2, 0}, {1, 3}};

  vector<vector<int>> bridges = criticalConnections(n, connections);

  cout << "Bridges:\n";
  for (auto &it : bridges) {
    cout << it[0] << " " << it[1] << "\n";
  }

  return 0;
}