#include <bits/stdc++.h>
using namespace std;

int bruteLargestRectangleHistogram(vector<int> arr) {
  // TC O(N^2)
  // SC O(1)
  // Brute Force is simple we try to trverse in each direction
  // Get the values that can be picked up and add up to width
  // then multiple by height
  int size = arr.size();
  int maxi = -1;
  for (int i = 0; i < size; i++) {
    int width = 1;
    int j = i - 1; // Left Area Span
    int localArea = 0;
    while (j >= 0) {
      if (arr[j] >= arr[i]) {
        width++;
        j--;
      } else {
        break;
      }
    }
    int k = i + 1; // Right Area Span
    while (k < size) {
      if (arr[k] >= arr[i]) {
        width++;
        k++;
      } else {
        break;
      }
    }
    localArea = arr[i] * width;
    maxi = max(maxi, localArea);
  }
  return maxi;
}

vector<int> findNse(vector<int> arr) {
  int size = arr.size();
  stack<int> st;
  vector<int> res(size);
  for (int i = size - 1; i >= 0; i--) {
    while (!st.empty() && arr[st.top()] >= arr[i]) {
      st.pop();
    }
    res[i] = st.empty() ? size : st.top();
    st.push(i);
  }

  return res;
}
vector<int> findPse(vector<int> arr) {
  int size = arr.size();
  stack<int> st;
  vector<int> res(size);
  for (int i = 0; i < size; i++) {
    while (!st.empty() && arr[st.top()] > arr[i]) {
      st.pop();
    }
    res[i] = st.empty() ? -1 : st.top();
    st.push(i);
  }

  return res;
}

int betterLargestRectangleHistogram(vector<int> arr) {
  // TC O(5N)
  // SC O(4N)
  // We willl find pse and nse for all elements
  // for area we can simply do
  // arr[i] * (nse - pse -1) we will get area for each element
  // and can simply find the max from this array
  int size = arr.size();
  vector<int> areas;
  vector<int> pse = findPse(arr);  // TC O(2N) SC O(2N)
  vector<int> nse = findNse(arr);  // TC O(2N) SC O(2N)
  for (int i = 0; i < size; i++) { // TC O(N)
    // NO space complexity if we use below apporach
    int width = nse[i] - pse[i] - 1;
    // We are storing index so we can simply subtract them
    int area = arr[i] * width;
    areas.push_back(area);
  }

  int res = 0;
  for (int i = 0; i < size; i++) {
    res = max(res, areas[i]);
  }
  return res;

  // We can also simply do

  int maxi = 0;
  for (int i = 0; i < size; i++) {
    maxi = max(maxi, arr[i] * (nse[i] - pse[i] - 1));
  }
  return maxi;
}

int main() {
  cout << "16 L12 Largest Rectangle in Histogram" << endl;
  // Array of integers, every value representing Height of
  // rectangle(bar/histogram)
  // Width is always one
  // We need to give Area of Largest Histogram that we can form
  // Understand Concept by refering to
  // 16_L12_Largest_Rectangle_in_Histogram_1
  // 16_L12_Largest_Rectangle_in_Histogram_2
  // 16_L12_Largest_Rectangle_in_Histogram_3

  vector<int> arr = {2, 1, 5, 6, 2, 3};
  int res = bruteLargestRectangleHistogram(arr);
  cout << res << endl;
  int res2 = betterLargestRectangleHistogram(arr);
  cout << res2 << endl;
  return 0;
}
