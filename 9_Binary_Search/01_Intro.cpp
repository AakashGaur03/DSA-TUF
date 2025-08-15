#include <bits/stdc++.h>
using namespace std;

// Iterative Approach
int binarySearch(vector<int> &arr, int size, int searchElem) {

  int low = 0;
  int high = size - 1;

  while (low <= high) {
    int mid = (low + high) / 2;

    // Safe mid calculation to avoid overflow
    // int mid = low + (high - low) / 2;

    if (arr[mid] == searchElem) {
      return mid;
    } else if (arr[mid] < searchElem) {
      low = mid + 1;
    } else {
      high = mid - 1;
    }
  }

  return -1;
}

int recursiveBinarySearch(vector<int> &arr, int low, int high, int searchElem) {
  if (low > high)
    return -1;
  int mid = (low + high) / 2;
  // int mid = low + (high-low)/2
  if (arr[mid] == searchElem) {
    return mid;
  } else if (arr[mid] < searchElem) {
    return recursiveBinarySearch(arr, mid + 1, high, searchElem);
  } else {
    return recursiveBinarySearch(arr, low, mid - 1, searchElem);
  }
}

// TC O(log2(N)) that is log base 2 N as it is dividing by 2

int main() {
  // In Linear Search TC is O(N) as we traverse each element in
  // the search space

  cout << "Binary Search" << endl;
  // Search Space must be Sorted
  // Look at middle of the Search Space
  // Acc to middle Trim down the search space that is for Ex
  // we have [3,4,6,7,9,12,16,17] we have to search 6
  // we will look at middle element that can be 7 or 9 we are taking it an
  // integer val so 7 then we see that 6 cant belong to right side we trim down
  // search space to be only left side that is 3 4 6
  // we again see the middle that will be 4 so it cant be on left so trim down
  // search space that is now 6 only so middle is pointing to 6, we found 6
  // So TC will be here log base 2 N

  vector<int> arr = {3, 4, 6, 7, 9, 12, 16, 17};
  int res = binarySearch(arr, arr.size(), 6);
  cout << res;

  int res2 = recursiveBinarySearch(arr, 0, arr.size() - 1, 6);
  cout << res2;

  // OVERFLOW CASE
  // int low = 0
  // int max = INT_MAX;
  // so what if at some case mid comes to something + INT_MAX
  // It cant compute that
  // so instead of int mid = (low+high)/2 we will do
  // we can take long long or
  // mid = low + (high-low)/2
  // how it works
  // simple maths we do common denominator so
  // mid - (2 * low + high - low)2
  // low + high /2

  return 0;
}
