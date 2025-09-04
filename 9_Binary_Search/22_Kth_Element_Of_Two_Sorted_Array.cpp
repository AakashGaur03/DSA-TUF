#include <bits/stdc++.h>
using namespace std;

int optimalKthElement(vector<int> &a, vector<int> &b, int n1, int n2, int k) {
  if (n1 > n2)
    return optimalKthElement(b, a, n2, n1, k);
  int low = max(0, k - n2);
  // In median one it was ok that there are no elements but here
  // K can be greater than array size so we need minimum of k-n2 elements
  int high = min(k, n1); // If k = 2 so we need at max 2 elements

  int left = k;
  int n = n1 + n2;
  while (low <= high) {
    int mid1 = (low + high) / 2;
    int mid2 = left - mid1;

    int l1 = INT_MIN, l2 = INT_MIN;
    int r1 = INT_MAX, r2 = INT_MAX;

    if (mid1 < n1) { // Means there is element in array1
      r1 = a[mid1];
    }
    if (mid2 < n2) { // Means there is element in array2
      r2 = b[mid2];
    }
    if (mid1 - 1 >= 0) {
      l1 = a[mid1 - 1];
    }
    if (mid2 - 1 >= 0) {
      l2 = b[mid2 - 1];
    }
    if (l1 <= r2 && l2 <= r1) {
      return max(l1, l2);
    } else if (l1 > r2)
      high = mid1 - 1;
    else
      low = mid1 + 1;
  }

  return 0;
}

int main() {
  cout << "22 Kth Element Of Two Sorted Array";
  // Same Problem as Median of two sorted Arrays there we were spliting in two
  // equal parts for even scenario and in odd in left there was 1 more than
  // right But here we have to find kth index so in left we will keep k and in
  // right k-n Rest problem is same only some edge cases need to be considered
  // while considering low and high

  vector<int> arr1 = {1, 3, 4, 7, 10, 12};
  vector<int> arr2 = {2, 3, 6, 15};
  double ans1 = optimalKthElement(arr1, arr2, arr1.size(), arr2.size(), 4);
  cout << "Kth Element = " << ans1 << endl;
  return 0;
}

// // mid1 = how many elements we are taking from array a
// // mid2 = how many elements we are taking from array b (k - mid1)

// // Initialize left and right values for both arrays
// int l1 = INT_MIN, l2 = INT_MIN; // "last element on the left side" of each
// array int r1 = INT_MAX,
//     r2 = INT_MAX; // "first element on the right side" of each array

// // ---------- Right boundaries ----------

// // If we haven't taken all elements from a, then the right side of a exists
// // r1 = first element on the right side of partition in array a
// if (mid1 < n1) {
//   r1 = a[mid1];
// }

// // If we haven't taken all elements from b, then the right side of b exists
// // r2 = first element on the right side of partition in array b
// if (mid2 < n2) {
//   r2 = b[mid2];
// }

// // ---------- Left boundaries ----------

// // If we have taken at least 1 element from a, then left side exists
// // l1 = last element on the left side of partition in array a
// if (mid1 - 1 >= 0) {
//   l1 = a[mid1 - 1];
// }