// Combination Sum III
// Find all valid combinations of k numbers that sum up to n such that the
// following conditions are true:

// Only numbers 1 through 9 are used.
// Each number is used at most once.
// Return a list of all possible valid combinations. The list must not contain
// the same combination twice, and the combinations may be returned in any
// order.

// Example 1:

// Input: k = 3, n = 7
// Output: [[1,2,4]]
// Explanation:
// 1 + 2 + 4 = 7
// There are no other valid combinations.
// Example 2:

// Input: k = 3, n = 9
// Output: [[1,2,6],[1,3,5],[2,3,4]]
// Explanation:
// 1 + 2 + 6 = 9
// 1 + 3 + 5 = 9
// 2 + 3 + 4 = 9
// There are no other valid combinations.
// Example 3:

// Input: k = 4, n = 1
// Output: []
// Explanation: There are no valid combinations.
// Using 4 different numbers in the range [1,9], the smallest sum we can get is
// 1+2+3+4 = 10 and since 10 > 1, there are no valid combination.

// class Solution {
// public:
//     void findCombinations(int k, int n, vector<int>& arr,
//                           vector<vector<int>>& res, int sum, int index) {
//         if (sum == n && arr.size() == k) {
//             res.push_back(arr);
//         }
//         if (sum > n || arr.size() > k)
//             return;

//         for (int i = index; i <= 9; i++) {
//             arr.push_back(i);
//             findCombinations(k, n, arr, res, sum + i, i + 1);
//             arr.pop_back();
//         }
//     }
//     vector<vector<int>> combinationSum3(int k, int n) {
//         vector<int> arr;
//         vector<vector<int>> res;
//         findCombinations(k, n, arr, res, 0, 1);
//         return res;
//     }
// };
#include <bits/stdc++.h>
using namespace std;

void findCombinations(int k, int n, vector<int> &arr, vector<vector<int>> &res,
                      int sum, int index) {
  if (sum == n && arr.size() == k) {
    res.push_back(arr);
    return;
  }

  if (sum > n || arr.size() > k)
    return;

  for (int i = index; i <= 9; i++) {
    arr.push_back(i);
    findCombinations(k, n, arr, res, sum + i, i + 1);
    arr.pop_back();
  }
}

vector<vector<int>> combinationSum3(int k, int n) {
  vector<int> arr;
  vector<vector<int>> res;
  findCombinations(k, n, arr, res, 0, 1);
  return res;
}

int main() {
  cout << "29 Combination Sum III" << endl;
  int k = 3, n = 9;

  vector<vector<int>> result = combinationSum3(k, n);

  cout << "Combinations:\n";
  for (auto &comb : result) {
    cout << "[ ";
    for (int x : comb) {
      cout << x << " ";
    }
    cout << "]\n";
  }

  return 0;
}