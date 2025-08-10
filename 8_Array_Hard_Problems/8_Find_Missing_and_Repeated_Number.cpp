#include <bits/stdc++.h>
using namespace std;

vector<int> bruteForceMissingAndRepeating(vector<int> arr, int size) {
  // TC O(N^2)

  // Loop from 1 to 6 find the number appearing twice that is repeating find
  // number appearing 0 times that is missing
  vector<int> res;
  int repeating = -1;
  int missing = -1;

  // First loop from 1 to <= size because traversing from 1 to n
  for (int i = 1; i <= size; i++) {
    int cnt = 0;
    // Second loop from 0 to < size because traversing in array
    for (int j = 0; j < size; j++) {
      if (i == arr[j]) {
        cnt++;
      }
    }
    if (cnt == 2) {
      repeating = i;
    } else if (cnt == 0) {
      missing = i;
    }
    if (repeating != -1 && missing != -1) {
      break;
    }
  }
  res.push_back(repeating);
  res.push_back(missing);

  cout << "repeating : " << repeating << endl;
  cout << "missing : " << missing << endl;
  return res;
}

vector<int> bettereMissingAndRepeating(vector<int> arr, int size) {
  // HASHING
  // TC:  O(N) for Hashing + O(N) for comparasion
  // SC : O(N)

  vector<int> hashArr(size + 1, 0);
  int repeating = -1;
  int missing = -1;

  for (int i = 0; i < size; i++) {
    hashArr[arr[i]]++;
  }

  for (int i = 1; i <= size; i++) {
    if (hashArr[i] == 0) {
      missing = i;
    } else if (hashArr[i] == 2) {
      repeating = i;
    }
    if (repeating != -1 && missing != -1) {
      break;
    }
  }
  cout << "repeating : " << repeating << endl;
  cout << "missing : " << missing << endl;

  return {repeating, missing};
}

int main() {
  cout << "8 Find Missing and Repeated Number" << endl;
  vector<int> arr = {4, 3, 6, 2, 1, 1};
  // We will be given List of integers from 1 to N we have to find out the
  // missing number and repeated number

  // vector<int> res = bruteForceMissingAndRepeating(arr, arr.size());
  vector<int> res = bettereMissingAndRepeating(arr, arr.size());
  for (auto it : res) {
    cout << it << " ";
  }

  return 0;
}