#include <bits/stdc++.h>
using namespace std;

vector<int> topoSort(int V, vector<vector<int>> &adj) {
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

string findOrder(vector<string> dict, int N, int K) {

  // Adjacency list for K characters (0 → 'a', 1 → 'b', ...)
  vector<vector<int>> adj(K);

  // Compare each pair of adjacent words
  for (int i = 0; i < N - 1; i++) {
    string s1 = dict[i];
    string s2 = dict[i + 1];

    // Only need to compare up to the smaller length
    int len = min(s1.size(), s2.size());

    // Edge Case:
    // If s1 is longer AND s2 is its prefix → invalid ordering
    // Example: ["abc", "ab"] → impossible in lexicographical order
    if (s1.size() > s2.size() && s1.substr(0, len) == s2) {
      return "";
    }

    // Find the first position where characters differ
    for (int ptr = 0; ptr < len; ptr++) {

      if (s1[ptr] != s2[ptr]) {

        // Key Idea:
        // The first mismatch determines ordering
        // s1[ptr] must come BEFORE s2[ptr]
        // So we add a directed edge: s1 → s2

        adj[s1[ptr] - 'a'].push_back(s2[ptr] - 'a');

        // Only the FIRST mismatch matters
        // Remaining characters give no ordering info
        break;
      }
    }
  }

  // Perform Topological Sort on the character graph
  vector<int> topo = topoSort(K, adj);

  // If topo doesn't include all characters → cycle exists
  // Means no valid ordering is possible
  if (topo.size() < K)
    return "";

  // Convert numeric topo order back to characters
  string ans = "";
  for (auto it : topo) {
    ans += char(it + 'a');
  }

  return ans;
}

int main() {
  cout << "23 G 26 Alien Dictionary Topological Sort" << endl;
  // A new alien language uses the English alphabet, but the order of letters is
  // unknown. You are given a list of words[] from the alien language’s
  // dictionary, where the words are claimed to be sorted lexicographically
  // according to the language’s rules.

  // Your task is to determine the correct order of letters in this alien
  // language based on the given words. If the order is valid, return a string
  // containing the unique letters in lexicographically increasing order as per
  // the new language's rules. If there are multiple valid orders, return any
  // one of them.

  // However, if the given arrangement of words is inconsistent with any
  // possible letter ordering, return an empty string ("").

  // A string a is lexicographically smaller than a string b if, at the first
  // position where they differ, the character in a appears earlier in the alien
  // language than the corresponding character in b. If all characters in the
  // shorter word match the beginning of the longer word, the shorter word is
  // considered smaller.

  // Note: Your implementation will be tested using a driver code. It will print
  // true if your returned order correctly follows the alien language’s
  // lexicographic rules; otherwise, it will print false.

  vector<string> dict = {"baa", "abcd", "abca", "cab", "cad"};
  int N = dict.size();
  int K = 4; // a, b, c, d

  string order = findOrder(dict, N, K);

  if (order == "") {
    cout << "Invalid dictionary (cycle or prefix issue)\n";
  } else {
    cout << "Character Order: " << order << endl;
  }

  return 0;
}