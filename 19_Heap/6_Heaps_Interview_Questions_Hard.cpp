#include <bits/stdc++.h>
using namespace std;

class CustomNode {
  // Node stored inside the min heap.
  // We need:
  // data -> current value
  // row    -> which array this value belongs to
  // col    -> index of this value inside that array
public:
  int data;
  int row; // row (array number)
  int col; // column (index in that array)
  CustomNode(int data, int row, int col) {
    this->data = data;
    this->row = row;
    this->col = col;
  }
};

class compare {
  // Comparator for Min Heap.
  // The smallest data value should come to the top.
public:
  bool operator()(CustomNode *a, CustomNode *b) {
    // Makes this class callable as a function.
    // Used by priority_queue to compare two nodes.
    return a->data > b->data;
  }
};

vector<int> kSorted(vector<vector<int>> &a, int k, int n) {
  int mini = INT_MAX;
  int maxi = INT_MIN;
  priority_queue<CustomNode *, vector<CustomNode *>, compare> minHeap;

  // Step 1
  for (int i = 0; i < k; i++) {
    int el = a[i][0];
    mini = min(mini, el);
    maxi = max(maxi, el);
    minHeap.push(new CustomNode(el, i, 0));
  }

  int start = mini;
  int end = maxi;

  // Step 2 Process Values
  while (!minHeap.empty()) {
    CustomNode *temp = minHeap.top();
    minHeap.pop();
    mini = temp->data;

    if (maxi - mini < end - start) {
      start = mini;
      end = maxi;
    }

    // Does next element exists in minHeap

    if (temp->col + 1 < a[temp->row].size()) {
      int data = a[temp->row][temp->col + 1];
      maxi = max(maxi, data);
      minHeap.push(new CustomNode(data, temp->row, temp->col + 1));
    } else {
      break;
    }
  }

  return {start, end};
}

int main() {
  cout << "6_Heaps_Interview_Questions_Hard" << endl;
  cout << "----------------------------------------------" << endl;
  cout << "Q1 Smallest Range in K lists" << endl;

  // You have k lists of sorted integers in non-decreasing order. Find the
  // smallest range that includes at least one number from each of the k
  // lists.

  // We define the range [a, b] is smaller than range [c, d] if b - a < d -
  // c or a < c if b - a == d - c.

  // Example 1:

  // Input: nums = [[4,10,15,24,26],[0,9,12,20],[5,18,22,30]]
  // Output: [20,24]
  // Explanation:
  // List 1: [4, 10, 15, 24,26], 24 is in range [20,24].
  // List 2: [0, 9, 12, 20], 20 is in range [20,24].
  // List 3: [5, 18, 22, 30], 22 is in range [20,24].

  // Brute Create all ranges take difference and check if exists in each list at
  // each step and in the end return the smallest different one
  // N = n*k TC
  // O(N*N)

  // Better
  // Take K pointers and take smallest element from each list that is k[0]
  // then find out min and max from those we have got our first Range
  // Now we will try to reduce the range
  // we will increase the minimum value and repeat the steps get the ranges
  // accordingly and if gets smaller range then take that and continue and in
  // the end return the ans
  // TC O(n*k*k)
  // TC O(k)

  // Optimal
  // Create Min Heap of K size and add starting element of each list
  // Track max element
  // And similar approach like better one
  // But heap will help us optimize the O(k) into O(log K)
  // TC O(N*log k)
  // SC O(k)

  vector<vector<int>> nums = {
      {4, 10, 15, 24, 26}, {0, 9, 12, 20}, {5, 18, 22, 30}};

  vector<int> ans = kSorted(nums, 3, 5);

  cout << "Smallest Range: [" << ans[0] << ", " << ans[1] << "]" << endl;

  return 0;
}
