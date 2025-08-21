#include <bits/stdc++.h>
using namespace std;

int brutePeakElement(vector<int> arr, int size) {
  // TC O(N)
  for (int i = 0; i < size; i++) {
    if ((i == 0 || arr[i - 1] < arr[i]) &&
        ((i == size - 1) || arr[i] > arr[i + 1])) {
      return i;
    }
  }
  return -1;
}
int optimalPeakElement(vector<int> arr, int size) {
  // TC O(log base2 n)

  if (size == 1)
    return 0;
  if (arr[0] > arr[1])
    return 0;
  if (arr[size - 1] > arr[size - 2])
    return size - 1;

  int low = 1;
  int high = size - 2;
  while (low <= high) {
    int mid = (low + high) / 2;
    if (arr[mid] > arr[mid - 1] && arr[mid] > arr[mid + 1]) {
      return mid;
    } else if (arr[mid] > arr[mid - 1]) {
      low = mid + 1;
    } else {
      high = mid - 1;
    }
  }

  return -1;
}

int main() {
  cout << "BS 7" << endl;
  vector<int> arr = {1, 2, 3, 4, 5, 6, 7, 8, 5, 1}; // peak =8
  vector<int> arr2 = {1, 2, 1, 3, 5, 6, 4};         // peak = 2 or 6
  // We assume at start and at end - infinity
  //   vector<int> arr3 =  -infinity {1,2,3,4,5}; - infinity peak = 5
  //   vector<int> arr3 =  -infinity {5,4,3,2,1};  - infinity peak = 5
  int res = brutePeakElement(arr, arr.size());
  cout << res << endl;
  int res2 = optimalPeakElement(arr, arr.size());
  cout << res2 << endl;
  return 0;
}