#include <bits/stdc++.h>
using namespace std;
vector<int> aestroidCollisions(vector<int> arr) {
  // TC O(2N)
  // SC O(N)
  int size = arr.size();
  vector<int> res;
  for (int i = 0; i < size; i++) { // O(N)
    if (arr[i] >= 0) {
      res.push_back(arr[i]);
    } else {
      // Stack has Elemetns that can collide and destroyed
      while (!res.empty() && res.back() > 0 && res.back() < abs(arr[i])) {
        // O(N)
        res.pop_back();
      }

      if (!res.empty() && res.back() == abs(arr[i])) {
        res.pop_back();
      } else if (res.empty() || res.back() < 0) {
        // IF empty or already megative value present
        res.push_back(arr[i]);
      }
    }
  }

  return res;
}
int main() {
  cout << "15 L11 Aestroid Collisions" << endl;
  // Positive value means Aestroid is moving in -> direction
  // Negative value means Aestroid is moving in <- direction
  // -> <- means collision
  // Aestroid with lesser value will be destryoed
  // If equal both will be destroyed
  // We need to give final state of Aestroids
  // For Concept Refer
  // 15_L11_Aestroid_Collisions_1, 15_L11_Aestroid_Collisions_2,
  // 15_L11_Aestroid_Collisions_3

  vector<int> arr = {4, 7, 1, 1, 2, -3, -7, 17, 15, -16};
  vector<int> res = aestroidCollisions(arr);
  for (auto it : res) {
    cout << it << " ";
  }

  return 0;
}
