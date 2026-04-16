#include <bits/stdc++.h>
using namespace std;

int main() {
  cout << "3 G 4 What are Connected Components" << endl;
  // It is not mandatory that graph will be connedted always
  // The below one is also a valid graph it will be called as there are 4
  // Components of a Single Graph
  // 3_G_4_What_are_Connected_Components_1

  // So when working on Traversal Algorithm we will use the concept of Visited
  // Array to keep track of all of them

  // We will be doing something like

  // for (int i = i; i < node; i++) {
  //    if(!vis[i]){
  //      traversal(i);
  //    }
  // }
  // traversal will make sure that each node that can be visisted are marked
  // So when i = 1 it marks 1 2 3 4
  // i = 2,3,4 doesn't do anything
  // So when i = 5 it marks 5 6 7
  // i = 6 7 doesn't do anything
  // So when i = 8 it marks 8 9
  // i = 9 doesn't do anything
  // So when i = 10 it marks 10

  return 0;
}