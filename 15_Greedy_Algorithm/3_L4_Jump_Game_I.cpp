#include <bits/stdc++.h>
using namespace std;

bool jumpGame1(vector<int> arr) {
  // TC O(N)
  // SC O(1)
  int maxIndex = 0;
  int size = arr.size();
  for (int i = 0; i < size; i++) {
    if (i > maxIndex) {
      return false;
    }
    maxIndex = max(maxIndex, arr[i] + i);
  }
  return true;
}

int main() {
  cout << "3 L4 Jump Game I" << endl;
  // Arr tells us what maximum we can jump
  // We need to tell that can we reach to last place or not
  vector<int> arr = {2, 3, 1, 0, 4};
  // vector<int> arr = {3, 2, 1, 0, 4};
  bool res = jumpGame1(arr);
  cout << res << endl;

  return 0;
}
