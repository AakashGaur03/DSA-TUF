#include <bits/stdc++.h>
using namespace std;

bool courseSchedule(int V, vector<pair<int, int>> &prerequisites) {
  vector<vector<int>> adj(V);

  for (auto it : prerequisites) {
    adj[it.second].push_back(it.first);
  }

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

  int cnt = 0;
  while (!q.empty()) {
    int node = q.front();
    q.pop();
    cnt++;
    for (auto adjNode : adj[node]) {
      indegree[adjNode]--;
      if (indegree[adjNode] == 0) {
        q.push(adjNode);
      }
    }
  }

  if (cnt == V) {
    // possible to complete all course (No Cycle)
    return true;
  }
  return false;
}
vector<int> courseScheduleII(int V, vector<pair<int, int>> &prerequisites) {

  vector<vector<int>> adj(V);

  for (auto it : prerequisites) {
    adj[it.second].push_back(it.first);
  }

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

  vector<int> res;
  while (!q.empty()) {
    int node = q.front();
    q.pop();
    res.push_back(node);
    for (auto adjNode : adj[node]) {
      indegree[adjNode]--;
      if (indegree[adjNode] == 0) {
        q.push(adjNode);
      }
    }
  }
  if (res.size() == V) {
    return res;
  } else {
    return {};
  }
}

int main() {
  cout << "21 G 24 Course Schedule I and II" << endl;
  // prerequisites = {{1, 0}};
  // To take course 1 → you must complete 0 first

  int V = 4;
  vector<pair<int, int>> prerequisites = {
      {1, 0}, // 0 → 1
      {2, 0}, // 0 → 2
      {3, 1}, // 1 → 3
      {3, 2}  // 2 → 3
  };

  // Course Schedule I
  if (courseSchedule(V, prerequisites)) {
    cout << "All courses can be completed\n";
  } else {
    cout << "Cycle detected, cannot complete courses\n";
  }

  // Course Schedule II
  vector<int> order = courseScheduleII(V, prerequisites);

  if (!order.empty()) {
    cout << "Valid course order: ";
    for (auto course : order) {
      cout << course << " ";
    }
    cout << endl;
  } else {
    cout << "No valid ordering (cycle present)\n";
  }

  return 0;
}