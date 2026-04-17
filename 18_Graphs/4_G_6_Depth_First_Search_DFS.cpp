#include <bits/stdc++.h>
using namespace std;

int main() {
  cout << "4 G 6 Depth First Search DFS" << endl;
  // Depth First Search (Level Wise)
  // Here Level is acc to distance Gap 1 to Level 1

  // Starting point 1

  //        1
  //     /    \
  //    2      3  -  4
  //  /  \     |     |
  // 5    6    7  -  8

  // 1 2 5 6 3 7 8 4
  // 1 3 7 8 4 2 6 5

  // Starting point 3
  //        1
  //     /    \
  //    2      3  -  4
  //  /  \     |     |
  // 5    6    7  -  8

  // 3 4 8 7 1 2 5 6
  // Here there can be multiple DFS one 3 goes to 4 and then further
  // Second 3 goes to 7 and then further
  // Third 3 goes to 1 and then further
  // and within them also

  // We will use Recursion to implement it

  // So Adj List
  // 1 -> {2,3}
  // 2 -> {1,5,6 }
  // 3 -> {1,4,7}
  // 4 -> {3,8}
  // 5 -> {2}
  // 6 -> {2}
  // 7 -> {3,8}
  // 8 -> {4,7}
  return 0;
}