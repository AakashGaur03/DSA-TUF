#include <bits/stdc++.h>
using namespace std;

vector<int> topoSort(int V, vector<int> adj[]) {
  // TC(V+E)
  // SC(2V)
  vector<int> indegree(V, 0);
  for (int i = 0; i < V; i++) {
    for (auto adjNode : adj[i]) {
      indegree[adjNode]++;
    }
  }

  queue<int> q;
  for (int i = 0; i < V; i++) {
    if (indegree[i] == 0) {
      q.push(i);
    }
  }

  vector<int> topo;
  while (!q.empty()) {
    int node = q.front();
    q.pop();
    topo.push_back(node);

    for (auto adjNode : adj[node]) {
      // node is in Topo Sort and remove it from InDegree
      indegree[adjNode]--;
      if (indegree[adjNode] == 0) {
        q.push(adjNode);
      }
    }
  }

  return topo;
}

int main() {
  cout << "19 G 22 Topological Sortting Kahns Algorithm | BFS" << endl;
  // Topological Sort only works on DAG means Directed Acyclic Graph
  // Directed + Graph that dont have any cycles

  // Topological Sort means any Linear ordering of vertices such that if there
  // is an edge between u & v, u appears before v in ordering

  // 0->{}
  // 5->0
  // 4->0
  // 5->2
  // 2->3
  // 3->1
  // 4->1

  // So Adj will be
  // 0 -> {}
  // 1 -> {}
  // 2 -> {3}
  // 3 -> {1}
  // 4 -> {0,1}
  // 5 -> {0,2}

  // so
  // 5 4 2 3 1 0
  // 4 5 2 3 1 0

  // These both are valid Linear Ordering as u->v
  // u appears before v
  // There can be multiple valid orderings

  // So Lets now understand why it works only in DAG (Directed Acyclic Graph)
  // So if a graph is Directed then u -> v and v -> u so it fails u appears
  // before v condition
  // Same as for cycle too it fails u appears before v condition

  // BFS
  // Here we will use an InDegree that is No. of incoming edges to a node
  // InDegree : No. of incoming edges to a node
  // So we will  store Only the Number for above case
  // For Above Example InDegree will be
  //  0  1  2  3  4  5
  // {2, 2, 1, 1, 0, 0}

  // So acc to indegree we can place 4 or 5 either one at start
  // and Note there will be minimum one node whose Indegree is Zero

  // So Step 1 will be Insert All Nodes in queue with InDegree Zero
  // Then Update the InDegree that those nodes are removed

  // SO when we add 4 In queue we will update the Indegree So it will be
  //  0  1  2  3  4  5
  // {1, 1, 1, 1, 0, 0}

  // then we add 5 and In queue we will update the Indegree So it will be
  //  0  1  2  3  4  5
  // {0, 1, 0, 1, 0, 0}

  // Now again we have 0 and 2 with Indegree 0 and we can repeat these steps and
  // update the Indegree and make them all 0

  int V = 6;
  vector<int> adj[V];

  adj[2].push_back(3);
  adj[3].push_back(1);
  adj[4].push_back(0);
  adj[4].push_back(1);
  adj[5].push_back(0);
  adj[5].push_back(2);

  vector<int> result = topoSort(V, adj);

  for (auto x : result) {
    cout << x << " ";
  }
  return 0;
}