#include <bits/stdc++.h>
using namespace std;

class DisjointSet {
  vector<int> rank, parent;

public:
  DisjointSet(int n) {
    rank.resize(n + 1, 0); // Resize and everything is 0 // Works for both 0
                           // based and 1 based indexing
    parent.resize(n + 1);
    for (int i = 0; i <= n; i++) {
      parent[i] = i; // In Parent Initally everything is set as themselves
    }
  }

  int findUPar(int node) { // Ultimate Parent
    if (node == parent[node]) {
      return node;
    }

    // return findUPar(parent[node]); // Normal Recursion

    return parent[node] = findUPar(parent[node]); // Path Compression
  }

  void unionByRank(int u, int v) {
    int ulp_u = findUPar(u);
    int ulp_v = findUPar(v);

    if (ulp_u == ulp_v) {
      // Already belong to same component
      return;
    }

    if (rank[ulp_u] < rank[ulp_v]) {
      // Means u gets attached to v as v is greater
      parent[ulp_u] = ulp_v;
    } else if (rank[ulp_v] < rank[ulp_u]) {
      // Means v gets attached to u as u is greater
      parent[ulp_v] = ulp_u;
    } else {
      // rank[ulp_v] == rank[ulp_u]
      // We can attach it anywhere But need to update Rank too
      parent[ulp_v] = ulp_u;
      rank[ulp_u]++;
    }
  }
};
class DisjointSet2 {
  vector<int> parent, size;

public:
  DisjointSet2(int n) {
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

int main() {

  cout << "43 G 46 Disjoint Set | Union by Rank | Union by Size | Path "
          "Compression"
       << endl;
  // Very Important Topics

  // Example are 1 and 5 belong to same Component or not
  // 1 -> 2 -> 3 -> 4
  // 5 -> 6 -> 7

  // So we will use BFS/DFS to search it and it will take up O(N+E)
  // So Disjoint helps us to find out this in constant time

  // Usually Used in Dynamic Graphs (Means graph that keeps on changing)

  // we have two options

  // findParent()
  // Union() (Rank and Size)

  // So what does Dynamic Graph Means

  // we will be given
  // {
  //   {1,2},
  //   {2,3},
  //   {4,5},
  //   {6,7},
  //   {5,6},
  //   {3,7},
  // }

  /*
  // At each step Union helps us to connect the nodes so {1,2} does is
  1 -> 2
  // At each step Union helps us to connect the nodes so {2,3} does is
  1 -> 2 ->3
  // At each step Union helps us to connect the nodes so {4,5} does is
  1 -> 2 ->3     4->5
  // At each step Union helps us to connect the nodes so {6,7} does is
  1 -> 2 ->3     4->5   6->7
  // At each step Union helps us to connect the nodes so {5,6} does is
  1 -> 2 ->3     4->5->6->7
  // At each step Union helps us to connect the nodes so {5,6} does is
  1 -> 2 ->3->7<-6<-5<-4
  */

  // So at each step we can be asked are 1 & 4 in same component
  // So as graph is changing It will be false till Last step at last step they
  // gets in same Components prior to that they are in different components so
  // this True or False we need to evaluate in Constant time

  // We will First Learn About Union By Rank
  // Here we will use two arrays Rank Array and Parent Array(this will serve in
  // findParent)

  // Initial Configuration
  // 43_G_46_Disjoint_Set__Union_by_Rank__Union_by_Size__Path_Compression_1

  // Pseudo Code for Union(u,v)
  // Find Ultimate Parent of u & v that is pu and pv
  // Find Rank of Ultimate Parents pu and pv
  // Connect Smaller Rank to Larger Rank always

  // In Union
  // So when we call each value like {1,2} or {2,3} or ...
  // We check there parents and there Rank
  // So Parent Array value will change acc to Rank and Rank will be give ++ when
  // new Node or Graph is being added and there Rank are same
  // After {1,2} or {2,3} our Rank and Parent will look like
  // 43_G_46_Disjoint_Set__Union_by_Rank__Union_by_Size__Path_Compression_2
  //  After {4,5}
  // 43_G_46_Disjoint_Set__Union_by_Rank__Union_by_Size__Path_Compression_3
  //  After {6,7}
  // 43_G_46_Disjoint_Set__Union_by_Rank__Union_by_Size__Path_Compression_4

  //  After {5,6}
  // 43_G_46_Disjoint_Set__Union_by_Rank__Union_by_Size__Path_Compression_5

  // NOTE whenever we will be asked that does x & y belong to same component we
  // will use findParent it will help us get the Ultimate Parents in normal
  // codition it will take log N as Refer to
  // 43_G_46_Disjoint_Set__Union_by_Rank__Union_by_Size__Path_Compression_6
  // To make it work in Constant Time we do Path Compression

  // Path Compression + Union by Rank/Size together give
  // amortized time complexity of O(alpha(N)) alpha is nearly 1 so considered
  // constant) Means attaching nested Nodes to the Ulitmate Parent directly
  // 43_G_46_Disjoint_Set__Union_by_Rank__Union_by_Size__Path_Compression_7
  // And NOTE when we do Path Compression we cant reduce the Rank because there
  // can be multiple nodes so thats why it is called Rank and not Height

  // So what we will do is
  // findParent(u){
  //   if(u == parent[u]){
  //     return u; // Node is its own parent
  //   }

  //   return findParent(parent[u]);
  // }
  // Before findParent
  // 43_G_46_Disjoint_Set__Union_by_Rank__Union_by_Size__Path_Compression_8
  // After
  // 43_G_46_Disjoint_Set__Union_by_Rank__Union_by_Size__Path_Compression_9

  /*
   if (rank[ulp_u] < rank[ulp_v]) {
      // Means u gets attached to v as v is greater
      parent[ulp_u] = ulp_v;
    } else if (rank[ulp_v] < rank[ulp_u]) {
      // Means v gets attached to u as u is greater
      parent[ulp_v] = ulp_u;
    } else {
      // rank[ulp_v] == rank[ulp_u]
      // We can attach it anywhere But need to update Rank too
      parent[ulp_v] = ulp_u;
      rank[ulp_u]++;
    }
  */

  // We are intentionally attaching Smaller to Larger so that Height Dont gets
  // increased if we connect Larger to Smaller
  // Attaching larger tree to smaller tree may increase depth significantly  So
  // to Avoid running Path Compression multiple times we do Smaller to Larger

  // We can also use size instead of rank
  // initial Config All size will be marked as 1 as each node is considered its
  // own parent
  // It is similar to Rank But It will keep track of the size of each component

  // UnionByRank and UnionBySize both have same TC and SC its just UnionBySize
  // is more intutive and makes more sense
  // TC = O(4 alpha) that is near about constant
  // O(α(N)) that is O(1) amortized
  // Amortized means Some individual operations may take longer, but over MANY
  // operations, the average time per operation becomes nearly constant.

  DisjointSet ds(7);
  ds.unionByRank(1, 2);
  ds.unionByRank(2, 3);
  ds.unionByRank(4, 5);
  ds.unionByRank(6, 7);
  // If 3 and 7 belong to same Component or not
  if (ds.findUPar(3) == ds.findUPar(7)) {
    cout << "Yes" << endl;
  } else {
    cout << "NO" << endl;
  }
  ds.unionByRank(3, 7);
  if (ds.findUPar(3) == ds.findUPar(7)) {
    cout << "Yes" << endl;
  } else {
    cout << "NO" << endl;
  }
  DisjointSet2 ds2(7);
  ds2.unionBySize(1, 2);
  ds2.unionBySize(2, 3);
  ds2.unionBySize(4, 5);
  ds2.unionBySize(6, 7);
  // If 3 and 7 belong to same Component or not
  if (ds2.findUPar(3) == ds2.findUPar(7)) {
    cout << "Yes" << endl;
  } else {
    cout << "NO" << endl;
  }
  ds2.unionBySize(3, 7);
  if (ds2.findUPar(3) == ds2.findUPar(7)) {
    cout << "Yes" << endl;
  } else {
    cout << "NO" << endl;
  }

  return 0;
}