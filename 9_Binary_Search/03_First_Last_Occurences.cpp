#include <bits/stdc++.h>
using namespace std;

vector<int> bruteFirstAndLast(vector<int> arr, int size, int target) {
  // TC O(N)
  int first = -1;
  int last = -1;

  for (int i = 0; i < size; i++) {
    if (arr[i] == target) {
      if (first == -1) {
        first = i;
      }
      last = i;
    }
  }

  return {first, last};
}

int lowerBound(vector<int> &arr, int size, int target) {

  // TC O(log base 2 N)
  int ans = size; // Hypothetical Answer
  int low = 0;
  int high = size - 1;

  while (low <= high) {
    int mid = low + (high - low) / 2;

    if (arr[mid] >= target) {
      ans = mid;
      high = mid - 1;
    } else {
      low = mid + 1;
    }
  }

  return ans;
}
int upperBound(vector<int> &arr, int size, int target) {

  // TC O(log base 2 N)
  int ans = size; // Hypothetical Answer
  int low = 0;
  int high = size - 1;

  while (low <= high) {
    int mid = low + (high - low) / 2;

    if (arr[mid] > target) {
      ans = mid;
      high = mid - 1;
    } else {
      low = mid + 1;
    }
  }

  return ans;
}

vector<int> optimalFirstAndLast(vector<int> arr, int size, int target) {
  // TC 2 * O(log n)

  // If all values are in array

  // We can use Lower Bound and Upper Bound
  // lower Bound will point to the first element
  // upper Bound will point to the first element that is after the target so we
  // need to just do -1

  // If Number is not present then we will check that if the index that we are
  // getting is equal to the target ot not

  // Also if lb points to n then also means it is not present

  int lb = lowerBound(arr, size, target);
  if (lb == size || arr[lb] != target)
    return {-1, -1};

  return {lb, upperBound(arr, size, target) - 1};
}

int firstOccurence(vector<int> arr, int size, int target) {
  int low = 0;
  int high = size - 1;
  int first = -1;

  while (low <= high) {
    int mid = low + (high - low) / 2;
    if (arr[mid] == target) {
      first = mid;
      high = mid - 1;
    } else if (arr[mid] < target)
      low = mid + 1;
    else {
      high = mid - 1;
    }
  }

  return first;
}
int lastOccurence(vector<int> arr, int size, int target) {
  int low = 0;
  int high = size - 1;
  int last = -1;

  while (low <= high) {
    int mid = low + (high - low) / 2;
    if (arr[mid] == target) {
      last = mid;
      low = mid + 1;
    } else if (arr[mid] < target)
      low = mid + 1;
    else {
      high = mid - 1;
    }
  }

  return last;
}

vector<int> optimalBSFirstAndLast(vector<int> arr, int size, int target) {
  // Plain Binary Search
  int first = firstOccurence(arr, size, target);
  if (first == -1)
    return {-1, -1};
  return {first, lastOccurence(arr, size, target)};
}

int main() {
  cout << "BS 3" << endl;

  // First and LAst Occurance of x;
  //  Index   0 1 2 3 4 5  6  7
  //   arr = [2,4,6,8,8,8,11,13]
  // x= 8
  // ans {3,5}
  // x= 10
  // ans {-1,-1}
  // x= 11
  // ans {6,6}
  vector<int> arr = {2, 4, 6, 8, 8, 8, 11, 13};
  vector<int> res = bruteFirstAndLast(arr, arr.size(), 8);

  for (auto it : res) {
    cout << it << " ";
  }
  cout << endl;

  vector<int> res2 = optimalFirstAndLast(arr, arr.size(), 8);

  for (auto it2 : res2) {
    cout << it2 << " ";
  }
  cout << endl;

  vector<int> res3 = optimalBSFirstAndLast(arr, arr.size(), 8);

  for (auto it3 : res3) {
    cout << it3 << " ";
  }
  cout << endl;

  return 0;
}