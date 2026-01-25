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

int maximalRectangle(vector<vector<int>> rectangle) {
  // TC O(N*M) + O(N* 2M)
  // SC O(M) + O(M)
  int n = rectangle.size();
  int m = rectangle[0].size();
  int maxArea = 0;
  vector<int> height(m, 0);

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (rectangle[i][j] == 1)
        height[j] += 1;
      else
        height[j] = 0;
    }

    maxArea = max(maxArea, optimalLargestRectangleHistogram(height));
  }

  return maxArea;
}
int main() {
  cout << "17 L13 Maximal Rectangle" << endl;
  // We will be gven nXm 2D matrix with 0s and 1s
  // We need to give area of maximal reactangle which has all 1s
  // For Understanding refer
  // 17_L13_Maximal_Rectangle_1 and 17_L13_Maximal_Rectangle_2
  // Concept of last problem will be used that is
  // 16_L12_Largest_Rectangle_in_Histogram

  // We will be traversing through and applying Largest_Rectangle_in_Histogram
  // Refer to 17_L13_Maximal_Rectangle_3 ,4 ,5 6 Figures

  // We will be using
  // 17_L13_Maximal_Rectangle_7
  // values to pass in 16_L12_Largest_Rectangle_in_Histogram Problem
  // These are basically coounts of one
  // and if there is 0 that means there is no Histogram

  // 1 0 1 0 1
  // 1 0 1 1 1
  // 1 1 1 1 1
  // 1 0 0 1 0

  vector<vector<int>> matrix = {
      {1, 0, 1, 0, 1}, {1, 0, 1, 1, 1}, {1, 1, 1, 1, 1}, {1, 0, 0, 1, 0}};

  cout << "Maximal Rectangle Area: " << maximalRectangle(matrix) << endl;
  return 0;
}
