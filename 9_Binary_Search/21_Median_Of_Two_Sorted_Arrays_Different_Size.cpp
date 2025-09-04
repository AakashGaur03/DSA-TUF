#include <bits/stdc++.h>
using namespace std;

double bruteMedian(vector<int> &a, vector<int> &b) {
  // TC O(N1+N2)
  // SC O(N1+N2)
  vector<int> arr3;

  int n1 = a.size();
  int n2 = b.size();

  int i = 0;
  int j = 0;

  while (i < n1 && j < n2) {
    if (a[i] < b[j]) {
      arr3.push_back(a[i++]);
    } else {
      arr3.push_back(b[j++]);
    }
  }
  while (i < n1)
    arr3.push_back(a[i++]);
  while (j < n2)
    arr3.push_back(b[j++]);

  int n = n1 + n2;
  if (n % 2 == 1) {
    return arr3[n / 2];
  } else {
    return (arr3[n / 2] + arr3[n / 2 - 1]) / 2.0;
  }
}

double betterMedian(vector<int> &a, vector<int> &b) {
  // TC O(N1+N2)
  // SC O()
  int n1 = a.size();
  int n2 = b.size();

  int i = 0;
  int j = 0;
  int n = n1 + n2;
  int ind2 = n / 2;
  int ind1 = ind2 - 1;

  int tracker = 0;
  int ind1El = -1;
  int ind2El = -1;

  while (i < n1 && j < n2) {

    if (a[i] < b[j]) {
      if (tracker == ind1) {
        ind1El = a[i];
      }
      if (tracker == ind2) {
        ind2El = a[i];
      }
      tracker++;
      i++;
    } else {
      if (tracker == ind1) {
        ind1El = b[j];
      }
      if (tracker == ind2) {
        ind2El = b[j];
      }
      tracker++;
      j++;
    }
  }

  while (i < n1) {
    if (tracker == ind1) {
      ind1El = a[i];
    }
    if (tracker == ind2) {
      ind2El = a[i];
    }
    tracker++;
    i++;
  }
  while (j < n2) {
    if (tracker == ind1) {
      ind1El = b[j];
    }
    if (tracker == ind2) {
      ind2El = b[j];
    }
    tracker++;
    j++;
  }
  if (n % 2 == 1) {
    return ind2El;
  } else {
    return (ind1El + ind2El) / 2.0;
  }
}

double optimalMedian(vector<int> &a, vector<int> &b) {
  // TC O(min(logn,logm))
  int n1 = a.size();
  int n2 = b.size();
  // Ensure that 'a' is always the smaller array
  // -> we only binary search on the smaller array for efficiency
  if (n1 > n2) {
    return optimalMedian(b, a);
  }
  int low = 0;
  int high = n1;
  int n = n1 + n2;
  // Number of elements we need in the left partition
  // If odd, left partition gets one more element
  int left = (n + 1) / 2;
  while (low <= high) {
    // mid1 = how many elements we take from array a
    int mid1 = (low + high) / 2;
    // mid2 = how many elements we take from array b
    int mid2 = left - mid1;
    // Left and Right boundary elements for both arrays
    // Initialize with extremes so we can handle edges cleanly
    int l1 = INT_MIN; // max element on left of a
    int l2 = INT_MIN; // max element on left of b
    int r1 = INT_MAX; // min element on right of a
    int r2 = INT_MAX; // min element on right of b
                      // Update actual values if in range
    if (mid1 < n1)
      r1 = a[mid1]; // right element from a
    if (mid2 < n2)
      r2 = b[mid2]; // right element from b
    if (mid1 - 1 >= 0)
      l1 = a[mid1 - 1]; // left element from a
    if (mid2 - 1 >= 0)
      l2 = b[mid2 - 1]; // left element from b

    // ✅ Check if partition is correct
    // l1 <= r2 AND l2 <= r1 means correct division
    if (l1 <= r2 && l2 <= r1) {
      if (n % 2 == 1) {
        // Odd total -> median is max of left part
        return max(l1, l2);
      } else {
        // Even total -> median is avg of max(left) and min(right)
        return (max(l1, l2) + min(r1, r2)) / 2.0;
      }
    }
    // ❌ Partition is wrong, adjust binary search
    else if (l1 > r2) {
      // Too many elements taken from 'a', move left
      high = mid1 - 1;
    } else {
      // Too few elements taken from 'a', move right
      low = mid1 + 1;
    }
  }
  // Should never reach here if inputs are valid
  return -1;
}

// Binary search on the basis of symetry
int main() {
  cout << "21 Median Of Two Sorted Arrays Different Size" << endl;
  // EX arr1 = {1,3,4,7,10,12} arr2={2,3,6,15}
  //   1,2,3,3,4,6,7,10,12,15
  // median = 4+6/2 = 5 (Because Even number of elements)

  // EX arr1 = {2,3,4} arr2={1,3}
  // so 1 2 3 3 4
  // Median = 3 middle element
  vector<int> arr1 = {1, 3, 4, 7, 10, 12};
  vector<int> arr2 = {2, 3, 6, 15};
  double ans1 = bruteMedian(arr1, arr2);
  cout << "Median = " << ans1 << endl;
  double ans2 = betterMedian(arr1, arr2);
  cout << "Median = " << ans2 << endl;
  double ans3 = optimalMedian(arr1, arr2);
  cout << "Median = " << ans3 << endl;
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