#include <bits/stdc++.h>
using namespace std;

void SubsequencesWithSumK(int i, vector<int> &ds, int sum, int arr[], int n,
                          int target) {
  if (i == n) {
    if (sum == target) {
      for (auto it : ds) {
        cout << it << " ";
      }
      cout << endl;
    }
    return;
  }

  sum += arr[i];
  ds.push_back(arr[i]);
  SubsequencesWithSumK(i + 1, ds, sum, arr, n, target);

  sum -= arr[i];
  ds.pop_back();
  SubsequencesWithSumK(i + 1, ds, sum, arr, n, target);
}

// To Print First Subsequence
bool OneSubsequenceWithSumK(int i, vector<int> &ds, int sum, int arr[], int n,
                            int target) {
  if (i == n) {
    if (sum == target) {
      for (auto it : ds) {
        cout << it << " ";
      }
      cout << endl;
      return true;
    }
    return false;
  }

  sum += arr[i];
  ds.push_back(arr[i]);
  if (OneSubsequenceWithSumK(i + 1, ds, sum, arr, n, target))
    return true;

  sum -= arr[i];
  ds.pop_back();
  if (OneSubsequenceWithSumK(i + 1, ds, sum, arr, n, target))
    return true;
  return false;
}

int main() {
  cout << "7 L7 All Kind of Patterns in Recursion" << endl;
  // Printing Subsequences whose sum is k
  int arr[] = {1, 2, 1};
  int n = 3;
  int sum = 0;
  int target = 2;
  vector<int> ds;
  SubsequencesWithSumK(0, ds, sum, arr, n, target);
  OneSubsequenceWithSumK(0, ds, sum, arr, n, target);
  return 0;
}