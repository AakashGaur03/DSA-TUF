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

int CountOfSubsequenceWithSumK(int i, vector<int> &ds, int sum, int arr[],
                               int n, int target) {
  if (i == n) {
    if (sum == target) {
      return 1;
    }
    return 0;
  }

  // Take
  ds.push_back(arr[i]);
  sum += arr[i];
  int left = CountOfSubsequenceWithSumK(i + 1, ds, sum, arr, n, target);
  // Not Take
  ds.pop_back();
  sum -= arr[i];
  int right = CountOfSubsequenceWithSumK(i + 1, ds, sum, arr, n, target);

  return left + right;
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
  // we can also remove the ds from this count one as we dont need it
  // we needed it for printing only
  int cnt = CountOfSubsequenceWithSumK(0, ds, sum, arr, n, target);
  cout << endl << "Count is :" << cnt << endl;
  return 0;
}

// Print Subsequence with Sum K similar to print all subsequece with base
// condition

// Print Only First
// We do it using flags means returning true on very first True

// Print Count of Subsequences
// Like Count of Subsequences with sum K
// we return 1 when base case it true and return 0 when false
// we do left = functionCall
// we do right = functionCall
// and in end do return left + right