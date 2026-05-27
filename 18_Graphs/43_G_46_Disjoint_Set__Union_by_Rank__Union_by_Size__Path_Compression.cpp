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

  // Path Compression (Performed in O(4*alpha) alpha is nearly 1 so considered
  // constant) Means attaching nested Nodes to the Ulitmate Parent directly
  // 43_G_46_Disjoint_Set__Union_by_Rank__Union_by_Size__Path_Compression_7
  // And NOTE when we do Path Compression we cant reduce the Rank because there
  // can be multiple nodes so thats why it is called Rank and not Height

  // So what we will do is
  // findParent(u){
  //   if(u == parent[u]){
  //     return u; // Means Self Looped
  //   }

  //   return findParent(parent[u]);
  // }
  // Before findParent
  // 43_G_46_Disjoint_Set__Union_by_Rank__Union_by_Size__Path_Compression_8
  // After
  // 43_G_46_Disjoint_Set__Union_by_Rank__Union_by_Size__Path_Compression_9

  return 0;
}