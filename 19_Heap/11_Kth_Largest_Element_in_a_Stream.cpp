#include <bits/stdc++.h>
using namespace std;

class KthLargest {

  //   Constructor: O(n log k) because it calls add() for each of the n
  //   elements.
  // add(): O(log k)
  // Space: O(k)
public:
  int K;
  priority_queue<int, vector<int>, greater<int>> minHeap;
  KthLargest(int k, vector<int> &nums) {
    K = k;
    for (int i = 0; i < nums.size(); i++) {
      add(nums[i]);
    }
  }

  int add(int val) {
    minHeap.push(val);
    while (minHeap.size() > K) {
      minHeap.pop();
    }
    return minHeap.top();
  }
};

int main() {
  cout << "11 Kth Largest Element in a Stream" << endl;

  // You are part of a university admissions office and need to keep track
  // of the kth highest test score from applicants in real-time. This helps
  // to determine cut-off marks for interviews and admissions dynamically as
  // new applicants submit their scores.

  // You are tasked to implement a class which, for a given integer k,
  // maintains a stream of test scores and continuously returns the kth
  // highest test score after a new score has been submitted. More
  // specifically, we are looking for the kth highest score in the sorted
  // list of all scores.

  // Implement the KthLargest class:

  // KthLargest(int k, int[] nums) Initializes the object with the integer k
  // and the stream of test scores nums. int add(int val) Adds a new test
  // score val to the stream and returns the element representing the kth
  // largest element in the pool of test scores so far.

  // Input:
  // ["KthLargest", "add", "add", "add", "add", "add"]
  // [[3, [4, 5, 8, 2]], [3], [5], [10], [9], [4]]

  // Output: [null, 4, 5, 5, 8, 8]

  // Explanation:

  // KthLargest kthLargest = new KthLargest(3, [4, 5, 8, 2]);
  // kthLargest.add(3); // return 4
  // kthLargest.add(5); // return 5
  // kthLargest.add(10); // return 5
  // kthLargest.add(9); // return 8
  // kthLargest.add(4); // return 8

  vector<int> nums = {4, 5, 8, 2};

  KthLargest kthLargest(3, nums);

  cout << kthLargest.add(3) << endl;  // 4
  cout << kthLargest.add(5) << endl;  // 5
  cout << kthLargest.add(10) << endl; // 5
  cout << kthLargest.add(9) << endl;  // 8
  cout << kthLargest.add(4) << endl;  // 8
  return 0;
}
