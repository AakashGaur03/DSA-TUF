
#include <bits/stdc++.h>
using namespace std;

int optimalLargestRectangleHistogram(vector<int> arr) {
  // TC O(2N)
  // SC O(N)
  // We will be applying the same formula
  // arr[i] * (nse - pse -1) we will get area for each element
  // But getting pse and nse on the fly
  // we can simply get pse as we iterate
  // nse is slightly tricky what we do is
  // we maintain a stack and whenever we get smaller value we get
  // nse of values that are bigger in stack

  int size = arr.size();
  stack<int> st;
  int maxArea = 0;

  for (int i = 0; i < size; i++) { // O(N)

    // If current bar is smaller, it becomes NSE for stack elements
    while (!st.empty() && arr[st.top()] > arr[i]) { // O(N)
      int element = st.top(); // index of bar whose area we calculate
      st.pop();
      int nse = i;                          // current index is NSE
      int pse = st.empty() ? -1 : st.top(); // new stack top is PSE
      maxArea = max(maxArea, arr[element] * (nse - pse - 1));
    }
    // push current index, stack remains increasing
    st.push(i);
  }
  // Remaining elements don't have NSE → NSE = size
  while (!st.empty()) {
    int nse = size;
    int element = st.top();
    st.pop();
    int pse = st.empty() ? -1 : st.top();
    maxArea = max(maxArea, arr[element] * (nse - pse - 1));
  }

  return maxArea;
}

int maximalRectangle(vector<vector<char>> &matrix) {

  int rows = matrix.size();
  int cols = matrix[0].size();

  vector<int> heights(cols, 0);

  int maxArea = 0;

  for (int i = 0; i < rows; i++) {

    // Build histogram for current row
    for (int j = 0; j < cols; j++) {

      if (matrix[i][j] == '1') {
        heights[j]++;
      } else {
        heights[j] = 0;
      }
    }

    // Find largest rectangle in current histogram
    maxArea = max(maxArea, optimalLargestRectangleHistogram(heights));
  }

  return maxArea;
}

int main() {

  cout << "55 DP 55 Maximum Rectangle Area with all 1's" << endl;

  // Maximal Rectangle
  // Given a rows x cols binary matrix filled with 0's and 1's, find the largest
  // rectangle containing only 1's and return its area.

  // Example 1:

  // Input: matrix =
  // [["1","0","1","0","0"],["1","0","1","1","1"],["1","1","1","1","1"],["1","0","0","1","0"]]
  // Output: 6
  // Explanation: The maximal rectangle is shown in the above picture.
  // Example 2:

  // Input: matrix = [["0"]]
  // Output: 0
  // Example 3:

  // Input: matrix = [["1"]]
  // Output: 1

  // Refer 16_L12_Largest_Rectangle_in_Histogram

  // Example 1
  vector<vector<char>> matrix1 = {{'1', '0', '1', '0', '0'},
                                  {'1', '0', '1', '1', '1'},
                                  {'1', '1', '1', '1', '1'},
                                  {'1', '0', '0', '1', '0'}};

  cout << "Example 1: " << maximalRectangle(matrix1) << endl;

  // Example 2
  vector<vector<char>> matrix2 = {{'0'}};

  cout << "Example 2: " << maximalRectangle(matrix2) << endl;

  // Example 3
  vector<vector<char>> matrix3 = {{'1'}};

  cout << "Example 3: " << maximalRectangle(matrix3) << endl;

  return 0;
}
