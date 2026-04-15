#include <bits/stdc++.h>
using namespace std;

int main() {
  cout << "2_G_2_Graph_Representation" << endl;
  // WE will be given that
  // Graph if Directed or Undirected
  // then also n and m
  // n represents Number of Nodes assume 5
  // m represents Number of Edges assume 5
  // After recieving n and m we will have to take input of 5 Nodes and 6 Edges
  // We will also be given M lines that represents Edges
  // (they can be given in any order)
  // Refer 2_G_2_Graph_Representation_1 and 2_G_2_Graph_Representation_2

  int n, m;
  cin >> n >> m;

  // We can store it in two ways
  // 1) Matrix
  // 2) List

  // 1) MATRIX
  // SPACE COMPLEXITY (N^2)
  // It is called as Adjacency Matrix
  // If it is 1 based Indexing
  // we will take a matix of adjacency matrix[n+1][n+1] size
  // Now we will mark the m lines that are given to us as 1 in the matrix
  // Example if Indirected Graph and given 1,2
  // So we will mark both 1,2 and 2,1 as 1
  // 2_G_2_Graph_Representation_3

  // All the remaing can be filled with 0 or -1
  // NOTE if it is a weighted graph we can simply store weight instead of 1

  // STORING GRAPH IN MATRIX
  int adj[n + 1][n + 1];
  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    adj[u][v] = 1;
    adj[v][u] = 1;
  }

  // 2) LIST
  // Space O(2E) // Undirected Graph
  // Space O(E) // Directed Graph
  // It is called as Adjacency List/Array
  // We will create an n+1 size array
  // 2_G_2_Graph_Representation_4
  // So now Every index contains an empty vector
  // We will be storing at each index that at that number how may other Nodes
  // are connected
  // So for each M line we will be adding a value in the index
  // Refer 2_G_2_Graph_Representation_5

  vector<int> adjArr[n + 1];
  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    adjArr[u].push_back(v);
    adjArr[v].push_back(u); // This will not be required if Directed Graph
    // NOTE if it is a weighted graph we will have to store them in the pairs
    // Like adjArr[u].push_back({v,wt});
  }

  return 0;
}
