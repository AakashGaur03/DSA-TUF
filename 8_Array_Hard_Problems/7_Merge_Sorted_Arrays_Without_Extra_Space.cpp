#include <bits/stdc++.h>
using namespace std;

void bruteForceApproach(vector<int> &arr1, vector<int> &arr2, int n, int m) {
  // In Brute Force Approach we will be using extra Space
  // TC O( N + M )for storing in arr3 + O(N + M) for placing them back in arr1
  // and arr 2
  // SC O( N + M )
  vector<int> arr3;
  int left = 0;
  int right = 0;
  int index = 0;

  while (left < n && right < m) {
    if (arr1[left] <= arr2[right]) {
      arr3.push_back(arr1[left]);
      left++;
    } else {
      arr3.push_back(arr2[right]);
      right++;
    }
  }
  while (left < n) {
    arr3.push_back(arr1[left]);
    left++;
  }
  while (right < m) {
    arr3.push_back(arr2[right]);
    right++;
  }
  for (int i = 0; i < arr3.size(); i++) {
    if (i < n)
      arr1[i] = arr3[i];
    else
      arr2[i - n] = arr3[i];
  }
}

void optimalSolution1Merge(vector<int> &arr1, vector<int> &arr2, int n, int m) {
  // TC : O(min(n,m)) + O(n log n) + O(m log m)
  // SC : O(1)
  int left = n - 1;
  int right = 0;

  // Step 1: Swap elements if arr1 has bigger values at the end
  // and arr2 has smaller values at the start
  while (left >= 0 && right < m) {
    if (arr1[left] > arr2[right]) {
      swap(arr1[left], arr2[right]);
      left--;
      right++;
    } else {
      break;
    }
  }

  // Step 2: Sort both arrays individually
  sort(arr1.begin(), arr1.end());
  sort(arr2.begin(), arr2.end());
}

// Helper function to swap only if the element in arr1 is greater than the
// element in arr2
void swapIFGreater(vector<int> &arr1, vector<int> &arr2, int ind1, int ind2) {
  if (arr1[ind1] > arr2[ind2]) {
    swap(arr1[ind1], arr2[ind2]);
  }
}

// Main function using the GAP method
void optimalSolution2Merge(vector<int> &arr1, vector<int> &arr2, int n, int m) {
  // The GAP method works by comparing elements that are 'gap' distance apart
  // and swapping them if they're out of order.
  // Gradually, the gap shrinks until it becomes 1, at which point the arrays
  // are sorted and merged.

  int len =
      n + m; // Total length when both arrays are considered as one sequence

  // Initial gap = ceiling(len / 2)
  int gap = (len / 2) + (len % 2);

  while (gap > 0) {
    int left = 0;           // Pointer to the first element in the comparison
    int right = left + gap; // Pointer to the second element in the comparison

    // Traverse through the combined "virtual" array
    while (right < len) {
      if (left < n && right >= n) {
        // Case 1: left is in arr1, right is in arr2
        swapIFGreater(arr1, arr2, left, right - n);

      } else if (left >= n) {
        // Case 2: both left and right are in arr2
        swapIFGreater(arr2, arr2, left - n, right - n);

      } else {
        // Case 3: both left and right are in arr1
        swapIFGreater(arr1, arr1, left, right);
      }

      left++;
      right++;
    }

    // If gap becomes 1, the next gap will be 0, so break out
    if (gap == 1)
      break;

    // Update the gap: new gap = ceiling(gap / 2)
    gap = (gap / 2) + (gap % 2);
  }
}

int main() {
  cout << "7 Merge Sorted Arrays Without Extra Space" << endl;

  vector<int> arr1 = {1, 4, 7, 8, 10};
  vector<int> arr2 = {2, 3, 9};

  bruteForceApproach(arr1, arr2, arr1.size(), arr2.size());

  cout << "Merged arr1: ";
  for (int x : arr1)
    cout << x << " ";
  cout << endl;

  cout << "Merged arr2: ";
  for (int x : arr2)
    cout << x << " ";
  cout << endl;

  return 0;
}