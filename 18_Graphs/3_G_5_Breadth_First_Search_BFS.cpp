#include <bits/stdc++.h>
using namespace std;

int main() {
  cout << "3 G 5 Breadth First Search BFS" << endl;
  // Graph can be 1 based or 0 Based
  // Breadth First Search (Level Wise)
  // Here Level is acc to distance Gap 1 to Level 1

  //        1                  // Level 1
  //     /    \
  //    2      6              // Level 2
  //  /  \    / \
  // 3    4  7   8            // Level 3
  //      \ /
  //       5                  // Level 4

  // 1 2 6 3 4 7 8 5
  // 1 6 2 8 7 4 3 5
  // Both are Valid Doesnt matter Left to Right or Right to left

  // Starting Point is 6
  // Starting point can only be 1

  //        1
  //     /    \
  //    2      6
  //  /  \    / \
  // 3    4  7   8
  //      \ /
  //       5

  // Now From 6: 1 7 8 are at level 1 as they have distance 1
  // Now From 6: 2 5 are at level 2 as they have distance 2
  // Now From 6: 3 4 are at level 3 as they have distance 3
  // So 6 1 7 8 2 5 3 4
  // or 6 8 7 1 5 2 3 4
  // Both are valid

  // So how do we Traverse then
  // We will take a Queue DS
  // and put the Starting Node in it
  // Also from 2_G_2_Graph_Representation we will have Adj List
  // That will have who all can be traversed from that particluar Node

  // So Adj List
  // 0 -> {}
  // 1 -> {2,6}
  // 2 -> {1,3,4}
  // 3 -> {2}
  // 4 -> {2,5}
  // 5 -> {4,8}
  // 6 -> {1,7,9}
  // 7 -> {6,8}
  // 8 -> {5,7}
  // 9 -> {6}

  // So we will push Starting node in Queue

  // |    |
  // |    |
  // |    |
  // | 1  |
  // | _  |

  // pop it out and push values from
  // its Adj List that is then 2 ,6
  // also mark the Visited array when Poping out 1
  // |    |
  // | 6  |
  // | 2  |
  // | 1  | -> Poped Out
  // | _  |

  // Then we will pop out 2 and see Items in Adj List 1 3 4 But 1 is already
  // isited so will push 3 4 in Queue
  // | 4  |
  // | 3  |
  // | 6  |
  // | 2  | -> Poped Out
  // | _  |

  // and then so on and we can Travese Whole Graph

  return 0;
}