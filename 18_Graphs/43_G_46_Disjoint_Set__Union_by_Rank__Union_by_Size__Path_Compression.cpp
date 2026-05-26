#include <bits/stdc++.h>
using namespace std;

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

  return 0;
}