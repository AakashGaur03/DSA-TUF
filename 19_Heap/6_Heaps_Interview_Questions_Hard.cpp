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

int signum(int a, int b) {
  if (a == b) {
    return 0;
  } else if (a > b) {
    return 1;
  } else {
    return -1;
  }
}

void callmedian(int element, priority_queue<int> &maxi,
                priority_queue<int, vector<int>, greater<int>> &mini,
                int &median) {
  switch (signum(maxi.size(), mini.size())) {
  case 0:
    if (element > median) {
      mini.push(element);
      median = mini.top();
    } else {
      maxi.push(element);
      median = maxi.top();
    }
    break;
  case 1:
    if (element > median) {
      mini.push(element);
      median = (mini.top() + maxi.top()) / 2;
    } else {
      mini.push(maxi.top());
      maxi.pop();
      maxi.push(element);
      median = (mini.top() + maxi.top()) / 2;
    }
    break;
  case -1:
    if (element > median) {
      maxi.push(mini.top());
      mini.pop();
      mini.push(element);
      median = (mini.top() + maxi.top()) / 2;
    } else {
      maxi.push(element);
      median = (mini.top() + maxi.top()) / 2;
    }
    break;
  default:
    break;
  }
}

vector<int> findMedian(vector<int> &arr, int n) {
  // TC O(n log n)
  vector<int> ans;
  priority_queue<int> maxHeap;
  priority_queue<int, vector<int>, greater<int>> minHeap;
  int median = 0;
  for (int i = 0; i < n; i++) {
    callmedian(arr[i], maxHeap, minHeap, median);
    ans.push_back(median);
  }

  return ans;
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

  cout << "----------------------------------------------" << endl;
  cout << "Median of a Stream" << endl;
  //   Median of a Stream
  // Last Updated : 11 May, 2026
  // Given a data stream arr[] where integers are read sequentially, Determine
  // the median of the elements encountered so far after each new integer is
  // read.

  // There are two cases for median on the basis of data set size.

  // If the data set has an odd number then the middle one will be consider as
  // median. If the data set has an even number then there is no distinct middle
  // value and the median will be the arithmetic mean of the two middle values.
  // Example:

  // Input:  arr[] = [5, 15, 1, 3, 2, 8]
  // Output: [5.00, 10.00, 5.00, 4.00, 3.00, 4.00]
  // Explanation:
  // After reading 1st element of stream - 5 -> median = 5
  // After reading 2nd element of stream - 5, 15 -> median = (5+15)/2 = 10
  // After reading 3rd element of stream - 5, 15, 1 -> median = 5
  // After reading 4th element of stream - 5, 15, 1, 3 ->  median = (3+5)/2 = 4
  // After reading 5th element of stream - 5, 15, 1, 3, 2 -> median = 3
  // After reading 6th element of stream - 5, 15, 1, 3, 2, 8 ->  median =
  // (3+5)/2 = 4

  // Note this is a Running Stream so After sorting an Element can come again
  // So we need to take care of also what kinda sorting we are applying

  // Approach 1
  // Sort using Insertion Sort O(N*N)
  // Get the Median O(1)

  // Approach 2
  // So if we see we have Three Case
  // Case 1 ODD size Array
  // Left has n-1 elements Right has n elements

  // Case 2 ODD size Array
  // Left has n elements Right has n-1 elements

  // Case 3 EVEN size Array
  // Left has n elements Right has n elements

  // WE ALSO HAVE AN SIGNUM function what it does is
  // it takes two number signum(a,b) and
  // gives 0 if a == b
  // gives 1 if a > b
  // gives -1 if a < b

  vector<int> stream = {5, 15, 1, 3, 2, 8};

  vector<int> median = findMedian(stream, stream.size());

  cout << "Input Stream : ";
  for (int x : stream)
    cout << x << " ";

  cout << "\nRunning Median: ";
  for (int x : median)
    cout << x << " ";

  cout << endl;

  return 0;
}
