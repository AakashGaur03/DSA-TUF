#include <bits/stdc++.h>
using namespace std;

int bruteCountPairs(vector<int> arr, int size) {
  // TC O(N^2)
  // SC O(1)
  int cnt = 0;

  for (int i = 0; i < size; i++) {
    for (int j = i + 1; j < size; j++) {
      if (arr[i] > 2 * (arr[j]))
        cnt++;
    }
  }

  return cnt;
}

void mergeThem(vector<int> &arr, int low, int mid, int high) {
  int left = low;
  int right = mid + 1;
  vector<int> temp;
  while (left <= mid && right <= high) {
    if (arr[left] <= arr[right]) {
      temp.push_back(arr[left]);
      left++;
    } else {
      temp.push_back(arr[right]);
      right++;
    }
  }
  while (left <= mid) {
    temp.push_back(arr[left]);
    left++;
  }
  while (right <= high) {
    temp.push_back(arr[right]);
    right++;
  }

  for (int i = low; i <= high; i++) {
    arr[i] = temp[i - low];
  }
}

int countPairs(vector<int> &arr, int low, int mid, int high) {
  int right = mid + 1;
  int cnt = 0;
  for (int i = low; i <= mid; i++) {
    while (right <= high && arr[i] > 2 * arr[right]) {
      right++;
    }
    cnt += (right - (mid + 1));
  }
  return cnt;
}

int mergeSort(vector<int> &arr, int low, int high) {
  // Time Complexity
  // Divide O(log N)
  // Merge O(N)
  // So O(n log n)
  // SC : O(N) due to Temporary Array(Vector)
  // Divide and Merge
  int count = 0;
  if (low >= high)
    return count;
  int mid = (low + high) / 2;
  count += mergeSort(arr, low, mid);
  count += mergeSort(arr, mid + 1, high);

  count += countPairs(arr, low, mid, high);
  mergeThem(arr, low, mid, high);
  return count;
}

int optimalCountPairs(vector<int> arr, int size) {
  // TC O(2N logn)
  // SC O(n)

  return mergeSort(arr, 0, size - 1);
}

int main() {
  cout << "10 Reverse Pairs" << endl;
  // Find Number of Pairs in whcih Left element is Greater than twice of right
  // element

  vector<int> arr = {40, 25, 19, 12, 9, 6, 2};

  int res = bruteCountPairs(arr, arr.size());
  cout << "Result is " << res << endl;
  int res2 = optimalCountPairs(arr, arr.size());
  cout << "Result is " << res2 << endl;
  return 0;
}