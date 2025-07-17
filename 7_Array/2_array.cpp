#include <bits/stdc++.h>
using namespace std;
int bruteMissingNumber(vector<int> arr, int N) {
  // TC O(N^2)
  for (int i = 1; i <= N; i++) {
    int flag = 0;
    for (int j = 0; j < N - 1; j++) {
      if (arr[j] == i) {
        flag = 1;
        break;
      }
    }
    if (flag == 0) {
      return i;
    }
  }
  return -1;
}

int betterMissingNumber(vector<int> arr, int N) {
  // TC O(2N)
  // SC O(N)
  vector<int> hashArray(N + 1, 0);
  for (int i = 0; i < N - 1; i++) {
    hashArray[arr[i]]++;
  }
  for (int i = 1; i <= N; i++) {
    if (hashArray[i] == 0) {
      return i;
    }
  }
  return -1;
}

int optimalMissingNumber(vector<int> arr, int N) {
  // // Sum = (N * (N + 1) )/2
  // // TC O(N)
  // // SC O(1)
  // int sum = 0;
  // int totalSum = (N * (N + 1)) / 2;
  // for (int i = 0; i < arr.size(); i++) {
  //   sum += arr[i];
  // }

  // return totalSum - sum;

  // XoR
  // TC O(N)
  // when we XOR same number it is Zero
  // so 1 Xor 1 is zero
  // and 0 Xor any number is that number

  // int xorVal1 = 0;
  // for (int i = 1; i <= N; i++) {
  //   xorVal1 = xorVal1 ^ i;
  // }
  int xorVal1 = 0;
  int xorVal2 = 0;
  for (int i = 0; i < arr.size(); i++) {
    xorVal2 = xorVal2 ^ arr[i];
    xorVal1 = xorVal1 ^ (i + 1);
  }
  return xorVal1 ^ xorVal2;
}

int maxConsecutiveOnes(vector<int> arr) {
  // TC O(N)
  int max = 0;
  int count = 0;
  int n = arr.size();
  for (int i = 0; i < n; i++) {
    if (arr[i] == 1) {
      count++;
      if (count > max) {
        max = count;
      }
    } else {
      count = 0;
    }
  }
  return max;
}

int bruteNumberappearOnceOtherTwice(vector<int> arr) {
  // Linear Search
  // TC O(N^2)
  // SC O(1)
  for (int i = 0; i < arr.size(); i++) {
    int count = 0;
    for (int j = 0; j < arr.size(); j++) {
      if (arr[i] == arr[j]) {
        count++;
      }
    }
    if (count == 1)
      return arr[i];
  }
  return -1;
}
int betterNumberappearOnceOtherTwice(vector<int> arr) {
  // Hashing
  // TC O(3N)
  // SC O(Max(N))
  int maxi = 0;
  for (int i = 0; i < arr.size(); i++) {
    maxi = max(maxi, arr[i]);
  }
  vector<int> hashArr(maxi + 1, 0);
  for (int i = 0; i < arr.size(); i++) {
    hashArr[arr[i]]++;
  }

  // for (int i = 0; i < hashArr.size(); i++) {
  //   if (hashArr[i] == 1) {
  //     return i;
  //   }
  // }
  for (int i = 0; i < arr.size(); i++) {
    if (hashArr[arr[i]] == 1)
      return arr[i];
  }

  return -1;
  // Map
  // TC O(N log M) + O(N/2 + 1)  m is size of map

  // SC  N/2 + 1

  unordered_map<int, int> freq;

  for (int num : arr) {
    freq[num]++;
  }

  for (auto it : freq) {
    if (it.second == 1) {
      return it.first;
    }
  }

  return -1;
}

int optimalNumberAppearOnceOtherTwice(vector<int> arr) {
  // XOR
  // If Same number then 0 else that number so every number that is twicw will
  // be 0 and remains a number in last is answer
  // TC O(N);
  // SC O(1);
  int XorVal = 0;
  for (int i = 0; i < arr.size(); i++) {
    XorVal ^= arr[i];
  }
  return XorVal;
}
int main() {
  cout << " Array 2" << endl;
  // vector<int> arr = {1, 2, 3, 5};
  vector<int> arr2 = {1, 1, 1, 1, 0, 0, 1};
  vector<int> arr3 = {1, 1, 2, 2, 3, 3, 4};
  // int res = bruteMissingNumber(arr, 5);
  // int res = betterMissingNumber(arr, 5);
  // int res = optimalMissingNumber(arr, 5);
  // int res = maxConsecutiveOnes(arr2);
  // Number that appears once and the others twice
  // int res = bruteNumberappearOnceOtherTwice(arr3);
  // int res = betterNumberappearOnceOtherTwice(arr3);
  int res = optimalNumberAppearOnceOtherTwice(arr3);
  cout << "Number that appears once is : " << res << " ";
  return 0;
}