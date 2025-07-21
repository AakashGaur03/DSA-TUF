#include <bits/stdc++.h>
using namespace std;
int bruteMajorityElement(vector<int> arr, int size) {
  // TC O(N^2)
  for (int i = 0; i < size; i++) {
    int cnt = 0;
    for (int j = 0; j < size; j++) {
      if (arr[j] == arr[i]) {
        cnt++;
      }
    }
    if (cnt > size / 2)
      return arr[i];
  }

  return -1;
}
int betterMajorityElement(vector<int> arr, int size) {
  // TC O(N^Log n) + O(N)
  // SC O(N)
  // Hash Map
  map<int, int> hashMap;
  for (int i = 0; i < size; i++) {
    hashMap[arr[i]]++;
  }
  for (auto it : hashMap) {
    if (it.second > (size / 2)) {
      return it.first;
    }
  }

  return -1;
}

// Moore's Voting Algorithm
int optimalMajorityElement(vector<int> arr, int size) {
  // Apply Moore's Voting Algo
  // TC O(2N)
  // SC O(1)
  int el;
  int cnt = 0;
  for (int i = 0; i < size; i++) {
    if (cnt == 0) {
      el = arr[i];
      cnt = 1;
    } else if (arr[i] == el) {
      cnt++;
    } else {
      cnt--;
    }
  }

  // Verify if el is Majority or not
  int verCount = 0;
  for (int i = 0; i < size; i++) {
    if (arr[i] == el) {
      verCount++;
    }
  }
  if (verCount > size / 2)
    return el;

  return -1;
}

int main() {
  cout << " Array 6" << endl;
  vector<int> arr = {2, 2, 3, 1, 2, 3, 2};
  //   int res = bruteMajorityElement(arr, arr.size());
  //   int res = betterMajorityElement(arr, arr.size());
  int res = optimalMajorityElement(arr, arr.size());
  cout << "Result is: " << res;
  return 0;
}